
/******************************************************************************
 * 
 * Module Name: cmdebug - Debug print routines
 *
 *****************************************************************************/

/******************************************************************************
 *
 * 1. Copyright Notice
 *
 * Some or all of this work - Copyright (c) 1999, Intel Corp.  All rights
 * reserved.
 *
 * 2. License
 *
 * 2.1. This is your license from Intel Corp. under its intellectual property
 * rights.  You may have additional license terms from the party that provided
 * you this software, covering your right to use that party's intellectual
 * property rights.
 *
 * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a
 * copy of the source code appearing in this file ("Covered Code") an
 * irrevocable, perpetual, worldwide license under Intel's copyrights in the
 * base code distributed originally by Intel ("Original Intel Code") to copy,
 * make derivatives, distribute, use and display any portion of the Covered
 * Code in any form, with the right to sublicense such rights; and
 *
 * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent
 * license (with the right to sublicense), under only those claims of Intel
 * patents that are infringed by the Original Intel Code, to make, use, sell,
 * offer to sell, and import the Covered Code and derivative works thereof
 * solely to the minimum extent necessary to exercise the above copyright
 * license, and in no event shall the patent license extend to any additions
 * to or modifications of the Original Intel Code.  No other license or right
 * is granted directly or by implication, estoppel or otherwise;
 *
 * The above copyright and patent license is granted only if the following
 * conditions are met:
 *
 * 3. Conditions 
 *
 * 3.1. Redistribution of Source with Rights to Further Distribute Source.  
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification with rights to further distribute source must include
 * the above Copyright Notice, the above License, this list of Conditions,
 * and the following Disclaimer and Export Compliance provision.  In addition,
 * Licensee must cause all Covered Code to which Licensee contributes to
 * contain a file documenting the changes Licensee made to create that Covered
 * Code and the date of any change.  Licensee must include in that file the
 * documentation of any changes made by any predecessor Licensee.  Licensee 
 * must include a prominent statement that the modification is derived,
 * directly or indirectly, from Original Intel Code.
 *
 * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification without rights to further distribute source must
 * include the following Disclaimer and Export Compliance provision in the
 * documentation and/or other materials provided with distribution.  In
 * addition, Licensee may not authorize further sublicense of source of any
 * portion of the Covered Code, and must include terms to the effect that the
 * license from Licensee to its licensee is limited to the intellectual
 * property embodied in the software Licensee provides to its licensee, and
 * not to intellectual property embodied in modifications its licensee may
 * make.
 *
 * 3.3. Redistribution of Executable. Redistribution in executable form of any
 * substantial portion of the Covered Code or modification must reproduce the
 * above Copyright Notice, and the following Disclaimer and Export Compliance
 * provision in the documentation and/or other materials provided with the
 * distribution.
 *
 * 3.4. Intel retains all right, title, and interest in and to the Original
 * Intel Code.
 *
 * 3.5. Neither the name Intel nor any other trademark owned or controlled by
 * Intel shall be used in advertising or otherwise to promote the sale, use or
 * other dealings in products derived from or relating to the Covered Code
 * without prior written authorization from Intel.
 *
 * 4. Disclaimer and Export Compliance
 *
 * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED
 * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE
 * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,
 * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY
 * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A
 * PARTICULAR PURPOSE. 
 *
 * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES
 * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR
 * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,
 * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY
 * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL
 * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS
 * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY
 * LIMITED REMEDY.
 *
 * 4.3. Licensee shall not export, either directly or indirectly, any of this
 * software or system incorporating such software without first obtaining any
 * required license or other approval from the U. S. Department of Commerce or
 * any other agency or department of the United States Government.  In the
 * event Licensee exports any such software from the United States or
 * re-exports any such software from a foreign destination, Licensee shall
 * ensure that the distribution and export/re-export of the software is in
 * compliance with all laws, regulations, orders, or other restrictions of the
 * U.S. Export Administration Regulations. Licensee agrees that neither it nor
 * any of its subsidiaries will export/re-export any technical data, process,
 * software, or service, directly or indirectly, to any country for which the
 * United States government or any agency thereof requires an export license,
 * other governmental approval, or letter of assurance, without first obtaining
 * such license, approval or letter.
 *
 *****************************************************************************/

#define __CMDEBUG_C__

#include <acpi.h>

#define _COMPONENT          MISCELLANEOUS
        MODULE_NAME         ("cmdebug");



/*****************************************************************************
 * 
 * FUNCTION:    Get/Set debug level
 *
 * DESCRIPTION: Get or set value of the debug flag
 *
 *              These are used to allow user's to get/set the debug level
 *
 ****************************************************************************/


INT32
GetDebugLevel (void)
{

    return DebugLevel;
}

void
SetDebugLevel (
    INT32                   NewDebugLevel)
{

    DebugLevel = NewDebugLevel;
}


/*****************************************************************************
 * 
 * FUNCTION:    FunctionTrace
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              FunctionName        - Name of Caller's function
 *
 * RETURN:      None
 *
 * DESCRIPTION: Function entry trace.  Prints only if TRACE_FUNCTIONS bit is
 *              set in DebugLevel
 *
 ****************************************************************************/

void
FunctionTrace (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    char                    *FunctionName)
{
        
    Gbl_NestingLevel++;  
    
    DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                " %2.2ld Entered Function: %s\n", Gbl_NestingLevel, FunctionName);
}


/*****************************************************************************
 * 
 * FUNCTION:    FunctionTracePtr
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              FunctionName        - Name of Caller's function
 *              Pointer             - Pointer to display
 *
 * RETURN:      None
 *
 * DESCRIPTION: Function entry trace.  Prints only if TRACE_FUNCTIONS bit is
 *              set in DebugLevel
 *
 ****************************************************************************/

void
FunctionTracePtr (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    char                    *FunctionName,
    void                    *Pointer)
{

    Gbl_NestingLevel++;
    DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                " %2.2ld Entered Function: %s, 0x%p\n", 
                Gbl_NestingLevel, FunctionName, Pointer);
}


/*****************************************************************************
 * 
 * FUNCTION:    FunctionTraceStr
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              FunctionName        - Name of Caller's function
 *              String              - Additional string to display
 *
 * RETURN:      None
 *
 * DESCRIPTION: Function entry trace.  Prints only if TRACE_FUNCTIONS bit is
 *              set in DebugLevel
 *
 ****************************************************************************/

void
FunctionTraceStr (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    char                    *FunctionName,
    char                    *String)
{

    Gbl_NestingLevel++;
    DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                " %2.2ld Entered Function: %s, %s\n", 
                Gbl_NestingLevel, FunctionName, String);
}


/*****************************************************************************
 * 
 * FUNCTION:    FunctionTraceU32
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              FunctionName        - Name of Caller's function
 *              Integer             - Integer to display
 *
 * RETURN:      None
 *
 * DESCRIPTION: Function entry trace.  Prints only if TRACE_FUNCTIONS bit is
 *              set in DebugLevel
 *
 ****************************************************************************/

void
FunctionTraceU32 (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    char                    *FunctionName,
    UINT32                  Integer)
{

    Gbl_NestingLevel++;
    DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                " %2.2ld Entered Function: %s, 0x%lX\n", 
                Gbl_NestingLevel, FunctionName, Integer);
}


/*****************************************************************************
 * 
 * FUNCTION:    FunctionExit
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              FunctionName        - Name of Caller's function
 *
 * RETURN:      None
 *
 * DESCRIPTION: Function exit trace.  Prints only if TRACE_FUNCTIONS bit is
 *              set in DebugLevel
 *
 ****************************************************************************/

void
FunctionExit (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    char                    *FunctionName)
{

    DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                " %2.2ld Exiting Function: %s\n", Gbl_NestingLevel, FunctionName);
    Gbl_NestingLevel--;
}


/*****************************************************************************
 * 
 * FUNCTION:    FunctionStatusExit
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              FunctionName        - Name of Caller's function
 *              Status              - Exit status code
 *
 * RETURN:      None
 *
 * DESCRIPTION: Function exit trace.  Prints only if TRACE_FUNCTIONS bit is
 *              set in DebugLevel.  Prints exit status also.
 *
 ****************************************************************************/

void
FunctionStatusExit (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    char                    *FunctionName,
    ACPI_STATUS             Status)
{

    if (Status > ACPI_MAX_STATUS)
    {
        DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                    " %2.2ld Exiting Function: %s, [Unknown Status] 0x%X\n", 
                    Gbl_NestingLevel, FunctionName, Status);
    }

    else
    { 
        DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                    " %2.2ld Exiting Function: %s, %s\n", 
                    Gbl_NestingLevel, FunctionName, CmFormatException (Status));
    }

    Gbl_NestingLevel--;
}


/*****************************************************************************
 * 
 * FUNCTION:    FunctionValueExit
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              FunctionName        - Name of Caller's function
 *              Value               - Value to be printed with exit msg
 *
 * RETURN:      None
 *
 * DESCRIPTION: Function exit trace.  Prints only if TRACE_FUNCTIONS bit is
 *              set in DebugLevel.  Prints exit value also.
 *
 ****************************************************************************/

void
FunctionValueExit (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    char                    *FunctionName,
    NATIVE_UINT             Value)
{

    DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                " %2.2ld Exiting Function: %s, 0x%X\n", 
                Gbl_NestingLevel, FunctionName, Value);
    Gbl_NestingLevel--;
}


/*****************************************************************************
 * 
 * FUNCTION:    FunctionPtrExit
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              FunctionName        - Name of Caller's function
 *              Value               - Value to be printed with exit msg
 *
 * RETURN:      None
 *
 * DESCRIPTION: Function exit trace.  Prints only if TRACE_FUNCTIONS bit is
 *              set in DebugLevel.  Prints exit value also.
 *
 ****************************************************************************/

void
FunctionPtrExit (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    char                    *FunctionName,
    char                    *Ptr)
{

    DebugPrint (ModuleName, LineNumber, ComponentId, TRACE_FUNCTIONS,
                " %2.2ld Exiting Function: %s, 0x%p\n", 
                Gbl_NestingLevel, FunctionName, Ptr);
    Gbl_NestingLevel--;
}


/*****************************************************************************
 * 
 * FUNCTION:    DebugPrint
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *              PrintLevel          - Requested debug print level
 *              Format              - Printf format field
 *              ...                 - Optional printf arguments
 *
 * RETURN:      None
 *
 * DESCRIPTION: Print error message with prefix consisting of the module name,
 *              line number, and component ID.
 *
 ****************************************************************************/

void
DebugPrint (
    char                    *ModuleName, 
    INT32                   LineNumber, 
    INT32                   ComponentId, 
    INT32                   PrintLevel, 
    char                    *Format,
    ...)
{
    va_list                 args;
     
     
    /* Both the level and the component must be enabled */

    if ((PrintLevel & DebugLevel) && (ComponentId & DebugLayer))
    {
        va_start (args, Format);

        OsdPrintf ("%8s-%04d: ", ModuleName, LineNumber);
        OsdVprintf (Format, args);  
    }
}


/*****************************************************************************
 * 
 * FUNCTION:    DebugPrintPrefix
 *
 * PARAMETERS:  ModuleName          - Caller's module name (for error output)
 *              LineNumber          - Caller's line number (for error output)
 *              ComponentId         - Caller's component ID (for error output)
 *
 * RETURN:      None
 *
 * DESCRIPTION: Print the prefix part of an error message, consisting of the
 *              module name, and line number
 *
 ****************************************************************************/

void
DebugPrintPrefix (
    char                    *ModuleName, 
    INT32                   LineNumber)
{


    OsdPrintf ("%8s-%04d: ", ModuleName, LineNumber);
}


/*****************************************************************************
 * 
 * FUNCTION:    DebugPrintRaw
 *
 * PARAMETERS:  Format              - Printf format field
 *              ...                 - Optional printf arguments
 *
 * RETURN:      None
 *
 * DESCRIPTION: Print error message -- without module/line indentifiers 
 *
 ****************************************************************************/

void
DebugPrintRaw (
    char                    *Format, 
    ...)
{
    va_list                 args;


    va_start (args, Format);

    OsdVprintf (Format, args);

    va_end (args);
}



/*****************************************************************************
 * 
 * FUNCTION:    CmDumpBuffer
 *
 * PARAMETERS:  Buffer              - Buffer to dump
 *              Count               - Amount to dump, in bytes
 *              ComponentID         - Caller's component ID
 *
 * RETURN:      None
 *
 * DESCRIPTION: Generic dump buffer in both hex and ascii.
 *
 ****************************************************************************/

void
CmDumpBuffer (
    char                    *Buffer, 
    UINT32                  Count, 
    UINT32                  Display,
    INT32                   ComponentId)
{
    UINT32                  i = 0;
    UINT32                  j;
    UINT8                   BufChar;


    /* Only dump the buffer if tracing is enabled */

    if (!((TRACE_TABLES & DebugLevel) && (ComponentId & DebugLayer)))
    {
        return;
    }


    /*
     * Nasty little dump buffer routine!
     */
    while (i < Count)
    {
        /* Print current offset */

        OsdPrintf ("%05X    ", i);


        /* Print 16 hex chars */

        for (j = 0; j < 16;)
        {
            if (i + j >= Count)
            {
                OsdPrintf ("\n");
                return;
            }

            /* Make sure that the char doesn't get sign-extended! */

            switch (Display)
            {
            /* Default is BYTE display */

            default:
                OsdPrintf ("%02X ", *((UINT8 *) &Buffer[i + j]));
                j += 1;
                break;

            case DB_WORD_DISPLAY:
                OsdPrintf ("%04X ", *((UINT16 *) &Buffer[i + j]));
                j += 2;
                break;

            case DB_DWORD_DISPLAY:
                OsdPrintf ("%08X ", *((UINT32 *) &Buffer[i + j]));
                j += 4;
                break;

            case DB_QWORD_DISPLAY:
                OsdPrintf ("%08X", *((UINT32 *) &Buffer[i + j]));
                OsdPrintf ("%08X ", *((UINT32 *) &Buffer[i + j + 4]));
                j += 8;
                break;
            }
        }


        /* 
         * Print the ASCII equivalent characters
         * But watch out for the bad unprintable ones...
         */

        for (j = 0; j < 16; j++)
        {
            if (i + j >= Count)
            {
                OsdPrintf ("\n");
                return;
            }

            BufChar = Buffer[i + j];
            if ((BufChar > 0x1F && BufChar < 0x2E) ||
                (BufChar > 0x2F && BufChar < 0x61) ||
                (BufChar > 0x60 && BufChar < 0x7F))
            {
                OsdPrintf ("%c", BufChar);
            }
            else
            {
                OsdPrintf (".");
            }
        }

        /* Done with that line. */

        OsdPrintf ("\n");
        i += 16;
    }

    return;
}





