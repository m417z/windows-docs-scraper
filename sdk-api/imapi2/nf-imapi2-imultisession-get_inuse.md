# IMultisession::get_InUse

## Description

Determines if this multi-session interface is the one you should use on the current media.

## Parameters

### `value` [out]

Is VARIANT_TRUE if this multi-session interface is the one you should use to write to the current media. Otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession)

[IMultisession::put_InUse](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-imultisession-put_inuse)