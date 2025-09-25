# IOleUIObjInfoW::GetConvertInfo

## Description

Gets the conversion information associated with the specified object.

## Parameters

### `dwObject` [in]

Unique identifier for the object.

### `lpClassID` [out]

Pointer to the location to return the object's CLSID.

### `lpwFormat` [out]

Pointer to the clipboard format of the object.

### `lpConvertDefaultClassID` [out]

Pointer to the default class, selected from the UI, to convert the object to.

### `lplpClsidExclude` [out]

Address of a pointer variable that receives a pointer to an array of CLSIDs that should be excluded from the user interface for this object. If *lpcClsidExclude* is zero, then *lpClsidExclude* is set to **NULL**.

### `lpcClsidExclude` [out]

Address of an output variable that receives the number of CLSIDs in *lplpClsidExclude*. This parameter may be zero.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

### Notes to Implementers

You must fill in the CLSID of the object at a minimum. *lpwFormat* may be left at zero if the format of the storage is unknown.

## See also

[IOleUIObjInfo](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuiobjinfoa)