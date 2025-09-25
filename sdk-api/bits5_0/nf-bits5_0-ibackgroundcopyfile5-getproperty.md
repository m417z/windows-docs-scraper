# IBackgroundCopyFile5::GetProperty

## Description

Gets a generic property of a BITS file transfer.

## Parameters

### `PropertyId` [in]

Specifies the file property whose value is to be retrieved.

### `PropertyValue` [out]

The property value, returned as a pointer to a BITS_FILE_PROPERTY_VALUE union. Use the union field appropriate for the property ID value passed in.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBackgroundCopyFile5](https://learn.microsoft.com/windows/desktop/api/bits5_0/nn-bits5_0-ibackgroundcopyfile5)

[IBackgroundCopyFile5.SetProperty](https://learn.microsoft.com/windows/desktop/api/bits5_0/nf-bits5_0-ibackgroundcopyfile5-setproperty)