# IRDPSRAPIViewer::get_DisconnectedText

## Description

[The [IRDPSRAPIViewer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiviewer) interface is no longer available for use for UWP applications as of Windows 10, version 1709. It is still supported for Desktop apps.]

Retrieves or sets the text that appears centered in the control before a connection is terminated.

This property is read/write.

## Parameters

## Remarks

Setting **DisconnectedText** is optional. If it is not specified, the control appears blank before a connection is established.

The **DisconnectedText** property can be set only if the control is not in the connected state. The method returns **E_FAIL** if it is called after the control is connected.

## See also

[IRDPSRAPIViewer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiviewer)