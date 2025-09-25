# IX509EndorsementKey::Close

## Description

Closes the endorsement key. You can only call the **Close** method after the [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509endorsementkey-open) method has been successfully called.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **Close** method releases any resources held
by the object except for the [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509endorsementkey-get_providername).
The **ProviderName** is released when it is re-assigned
or when this object is destroyed.

## See also

[IX509EndorsementKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509endorsementkey)