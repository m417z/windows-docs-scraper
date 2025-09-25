# IExtractImage2::GetDateStamp

## Description

Requests the date the image was last modified. This method allows the Shell to determine whether cached images are out-of-date.

## Parameters

### `pDateStamp`

Type: **FILETIME***

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure used to return the last time the image was modified.

## Return value

Type: **HRESULT**

Return S_OK if successful, or a COM-defined error code otherwise.