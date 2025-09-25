# IDWriteFactory::CreateTypography

## Description

 Creates a typography object for use in a text layout.

## Parameters

### `typography` [out]

Type: **[IDWriteTypography](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetypography)****

When this method returns, contains the address of a pointer to a newly created typography object, or **NULL** in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)