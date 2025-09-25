# ICredentialProviderCredential::GetBitmapValue

## Description

Enables retrieval of bitmap data from a credential with a bitmap field.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the field.

### `phbmp` [out]

Type: **HBITMAP***

Contains a pointer to the handle of the bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is optional.