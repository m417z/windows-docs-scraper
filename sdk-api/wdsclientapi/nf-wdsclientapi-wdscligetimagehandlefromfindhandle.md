# WdsCliGetImageHandleFromFindHandle function

## Description

Returns an image handle for the current image in an image enumeration.

## Parameters

### `FindHandle` [in]

A find handle returned by the [WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage) function. The image referenced by the find handle can be advanced using the [WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) function.

### `phImageHandle` [out]

A pointer to a location that contains an image handle for the current image referenced by the find handle.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

Use the [WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose) function to close the image handle returned by this function.