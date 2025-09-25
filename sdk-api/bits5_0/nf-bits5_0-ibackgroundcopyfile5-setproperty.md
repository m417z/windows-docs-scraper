# IBackgroundCopyFile5::SetProperty

## Description

Sets a generic property of a BITS file transfer.

## Parameters

### `PropertyId` [in]

Specifies the property to be set.

### `PropertyValue` [out]

A pointer to a union that specifies the value to be set. The union member appropriate for the property ID is used.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBackgroundCopyFile5](https://learn.microsoft.com/windows/desktop/api/bits5_0/nn-bits5_0-ibackgroundcopyfile5)

[IBackgroundCopyFile5.GetProperty](https://learn.microsoft.com/windows/desktop/api/bits5_0/nf-bits5_0-ibackgroundcopyfile5-getproperty)