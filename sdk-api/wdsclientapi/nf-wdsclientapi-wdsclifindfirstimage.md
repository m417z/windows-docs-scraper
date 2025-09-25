# WdsCliFindFirstImage function

## Description

Starts the enumeration of images stored on a WDS server and returns a find handle that references the first image.

## Parameters

### `hSession` [in]

A handle to a session with a WDS server. This was a handle returned by
the [WdsCliCreateSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicreatesession) function.

### `phFindHandle` [out]

Pointer to a **HANDLE** value that receives the find handle. If the function succeeds, the find handle will reference the first image stored on the WDS server. If the function is unsuccessful, this parameter is unchanged. Use the [WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) function to advance the reference of the find handle to the next image.

**Note** Information about the image can only be obtained from the find handle by using the image information functions of the WDS client API.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

 The session must be authenticated to use this function. To authenticate an existing session, call the
[WdsCliAuthorizeSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliauthorizesession) function.

The WDS image find handle returned by this function can be used with the [WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) function to enumerate the images stored on the WDS server.

## See also

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)