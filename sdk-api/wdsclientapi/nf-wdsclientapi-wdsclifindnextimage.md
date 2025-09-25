# WdsCliFindNextImage function

## Description

Advances the reference of a find handle to the next image stored on a WDS server.

## Parameters

### `Handle` [in]

The find handle returned by
the [WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage) function. If the **WdsCliFindNextImage** function is successful, the reference of the find handle is advanced to the next image stored on the WDS server.

## Return value

If the function succeeds, the return is **S_OK**.

If the function succeeds, and the end of the enumeration has been reached, the return is **HRESULT_FROM_WIN32(ERROR_NO_MORE_FILES)**.

## Remarks

To enumerate all the images on a WDS Server, first get the WDS image find handle by calling the [WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage) function, and then make repeated calls to **WdsCliFindNextImage** until the function returns **HRESULT_FROM_WIN32(ERROR_NO_MORE_FILES)**.

## See also

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)