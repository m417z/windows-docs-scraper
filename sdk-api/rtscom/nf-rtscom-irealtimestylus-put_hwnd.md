# IRealTimeStylus::put_HWND

## Description

Gets or sets the handle value associated with the window the [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object uses.

This property is read/write.

## Parameters

## Remarks

If two or more windows exist, this property allows you to specify which window collects ink.

The HRESULT E_INVALIDOPERATION is returned when you attempt set this property on a child [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object.

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::Enabled Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-get_enabled)

**RealTimeStylus Class**

[RealTimeStylus Reference](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-reference)