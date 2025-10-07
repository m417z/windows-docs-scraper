# GetNPPMacTypeAsNumber function

The **GetNPPMacTypeAsNumber** function retrieves the MAC type from the NetworkInfo category of the NPP section of the BLOB and converts the type data into a MAC type number.

## Parameters

*hBlob* \[in\]

A handle to the specified BLOB.

*lpMacType* \[out\]

A pointer to the MAC type.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the tag is unavailable, the return value is MAC\_TYPE\_UNKNOWN.

## Remarks

This function maps the tag, **NPP:NetworkInfo:MacType** to the **MAC\_TYPE\_\*** as defined in the Npptypes.h file.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

