# IX509EndorsementKey::ExportPublicKey

## Description

Exports the endorsement public key. You can only call the **ExportPublicKey** method after the [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509endorsementkey-open) method has been successfully called.

## Parameters

### `ppPublicKey` [out, retval]

The exported endorsement public key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IX509EndorsementKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509endorsementkey)