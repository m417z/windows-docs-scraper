# IMetaDataImport2::GetPEKind

## Description

Gets a value identifying the nature of the code in the portable executable (PE) file, typically a DLL or EXE file, that is defined in the current metadata scope.

## Parameters

### `pdwPEKind` [out]

 A pointer to a value of the [CorPEKind](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corpekind-enumeration) enumeration that describes the PE file.

### `pdwMAchine` [out]

A pointer to a value that identifies the architecture of the machine. See the next section for possible values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The value referenced by the *pdwMachine* parameter can be one of the following.

| Value | Machine architecture |
| --- | --- |
| IMAGE_FILE_MACHINE_I386<br><br>0x014C | x86 |
| IMAGE_FILE_MACHINE_IA64<br><br>0x0200 | Intel IPF |
| IMAGE_FILE_MACHINE_AMD64<br><br>0x8664 | x64 |

## See also

[IMetaDataImport2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport2)