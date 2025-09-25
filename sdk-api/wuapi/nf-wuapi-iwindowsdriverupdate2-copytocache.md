# IWindowsDriverUpdate2::CopyToCache

## Description

Copies the external update binaries to an update.

## Parameters

### `pFiles` [in]

An [IStringCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-istringcollection) interface that contains the strings to be copied to an update.

#### - ignoreDigests [in]

If the value of the *ignoreDigests* parameter is **VARIANT_TRUE**, Windows Update Agent (WUA) ignores the digest mismatches when WUA copies from the location represented by the *pFiles* parameter.

If the value of *ignoreDigests* is **VARIANT_FALSE**, WUA does not ignore the digest mismatches when WUA copies from the location represented by the *pFiles* parameter.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **E_INVALIDARG** | A parameter value is invalid. |
| **WU_E_INVALID_OPERATION** | The computer could not access the update site. |

## Remarks

This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the interface has been locked down.

## See also

[IWindowsDriverUpdate2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwindowsdriverupdate2)