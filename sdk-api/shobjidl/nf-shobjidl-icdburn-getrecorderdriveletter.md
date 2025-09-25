# ICDBurn::GetRecorderDriveLetter

## Description

Gets the drive letter of a CD drive that has been marked as write-enabled.

## Parameters

### `pszDrive` [out]

Type: **LPWSTR**

A pointer to a string containing the drive letter, for example "F:\".

### `cch` [in]

Type: **UINT**

The size of the string, in characters, pointed to by pszDrive. This value will normally be 4. Values larger than 4 are allowed, but the extra characters will be ignored by this method. Values less than 4 will generate an E_INVALIDARG error.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The drive whose letter designation is returned by this method is the drive that has the **Enable cd writing on this drive** option selected. This option is found on the drive's property sheet. Only one drive on a system can have this option selected.

If a recordable CD drive is present but that option has been deselected, the method will return an error code.