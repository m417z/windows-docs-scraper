# IAssocHandler::IsRecommended

## Description

Indicates whether the application is registered as a recommended handler for the queried file type.

## Return value

Type: **HRESULT**

Returns S_OK if the program is recommended; otherwise, S_FALSE.

## Remarks

Applications that register themselves as handlers for particular file types can specify whether they are recommended handlers. This has no effect on the actual behavior of the applications when launched. It is simply provided as a hint to the user and a value that the UI can utilize programmatically, if desired. For example, the Shell's **Open With** dialog separates entries into **Recommended Programs** and **Other Programs**.

Note that program recommendations may change over time. One example is provided when the user chooses an application from the **Other Programs** of the **Open With** dialog to open a particular file type. That may cause the Shell to "promote" that application to recommended status for that file type. Because the recommended status may change over time, applications should not cache this value, but query it each time it is needed.

If [SHAssocEnumHandlers](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shassocenumhandlers) was called with the ASSOC_FILTER_RECOMMENDED flag, then only recommended handlers are returned. If the ASSOC_FILTER_NONE flag was used, then you must call **IAssocHandler::IsRecommended** on each [IAssocHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandler) object to determine whether it is recommended or not.