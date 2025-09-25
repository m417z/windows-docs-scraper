# PIMAGEHLP_STATUS_ROUTINE callback function

## Description

An application-defined callback function used with the
[BindImageEx](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-bindimageex) function. The status routine is called during the process of the image binding.

The **PIMAGEHLP_STATUS_ROUTINE** type defines a pointer to this callback function.
**StatusRoutine** is a placeholder for the application-defined function name.

## Parameters

### `Reason` [in]

The current status of the bind operation. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BindOutOfMemory**<br><br>0 | Out of memory. The *Parameter* value is the number of bytes in the allocation attempt. |
| **BindRvaToVaFailed**<br><br>1 | The relative virtual address is invalid for the image. The *Parameter* value is not used. |
| **BindNoRoomInImage**<br><br>2 | No room in the image for new format import table. The *Parameter* value is not used. |
| **BindImportModuleFailed**<br><br>3 | Module import failed. The *Parameter* value is not used. |
| **BindImportProcedureFailed**<br><br>4 | Procedure import failed. The *Parameter* value is the name of the function. |
| **BindImportModule**<br><br>5 | Module import is starting. The *Parameter* value is not used. |
| **BindImportProcedure**<br><br>6 | Procedure import is starting. The *Parameter* value is the name of the function. |
| **BindForwarder**<br><br>7 | The *Parameter* value is the name of the function forwarded. |
| **BindForwarderNOT**<br><br>8 | The *Parameter* value is the name of the function not forwarded. |
| **BindImageModified**<br><br>9 | Image modified. The *Parameter* value is not used. |
| **BindExpandFileHeaders**<br><br>10 | File headers expanded. The *Parameter* value is the number of bytes |
| **BindImageComplete**<br><br>11 | Binding is complete. For more information on the *Parameter* value, see the following Remarks section. |
| **BindMismatchedSymbols**<br><br>12 | Checksum did not match. The *Parameter* value is the name of the symbol file. |
| **BindSymbolsNotUpdated**<br><br>13 | Symbol file was not updated. The *Parameter* value is the name of the symbol file not updated. |

### `ImageName` [in]

The name of the file to be bound. This value can be a file name, a partial path, or a full path.

### `DllName` [in]

The name of the DLL.

### `Va` [in]

The computed virtual address.

### `Parameter` [in]

Any additional status information. This value depends on the value of the *Reason* parameter. For more information, see the code fragment in the following Remarks section.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

The following code fragment describes how to use the *Va* value when the status is BindImageComplete.

```cpp
case BindImageComplete:
    if (fVerbose) {
        fprintf(stderr, "BIND: Details of binding %s\n", ImageName );
        NewImports = (PIMAGE_BOUND_IMPORT_DESCRIPTOR)Va;
        NewImport = NewImports;
        while (NewImport->OffsetModuleName) {
            fprintf( stderr, "    Import from %s [%x]",
                     (LPSTR)NewImports + NewImport->OffsetModuleName,
                     NewImport->TimeDateStamp
                   );
            if (NewImport->NumberOfModuleForwarderRefs != 0) {
                fprintf( stderr, " with %u forwarders", NewImport->
                         NumberOfModuleForwarderRefs );
            }
            fprintf( stderr, "\n" );
            NewForwarder = (PIMAGE_BOUND_FORWARDER_REF)(NewImport+1);
            for (i=0; i<NewImport->NumberOfModuleForwarderRefs; i++)
            {
                fprintf( stderr, "        Forward to %s [%x]\n",
                   (LPSTR)NewImports + NewForwarder->OffsetModuleName,
                   NewForwarder->TimeDateStamp);
                NewForwarder += 1;
            }
            NewImport = (PIMAGE_BOUND_IMPORT_DESCRIPTOR)NewForwarder;
        }
    }
    break;

```

## See also

[BindImageEx](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-bindimageex)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)