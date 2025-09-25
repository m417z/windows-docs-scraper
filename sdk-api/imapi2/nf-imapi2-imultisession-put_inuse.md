# IMultisession::put_InUse

## Description

Determines if this multi-session interface is the one you should use on the current media.

## Parameters

### `value` [in]

Set to VARIANT_TRUE if this multi-session interface is the one you should use to write to the current media. Otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## See also

[IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession)

[IMultisession::get_InUse](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-imultisession-get_inuse)