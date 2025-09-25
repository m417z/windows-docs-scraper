# ISdo::Apply

## Description

The
**Apply** method writes to persistent storage the changes made by calls to the
[ISdo::PutProperty](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-putproperty) method.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

To cancel changes made by
[ISdo::PutProperty](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-putproperty), call
[ISdo::Restore](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-restore).

## See also

[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo)

[ISdo::PutProperty](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-putproperty)

[ISdo::Restore](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-restore)