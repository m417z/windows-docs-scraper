# IRealTimeStylus::get_ChildRealTimeStylusPlugin

## Description

Gets or sets a [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object as an asynchronous plug-in of the current **RealTimeStylus** object.

This property is read/write.

## Parameters

## Remarks

If there is no child RTS, getting the property returns S_OK with the *ppiRTS* parameter set to **NULL**. Setting the child RTS property to **NULL** breaks the cascade.

**Note** If there is no child RTS, setting the property to **NULL** returns S_OK.

A child [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) cannot have another cascaded child **RealTimeStylus**.

Plug-ins in the asynchronous collection cannot have children.

If a [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object is set as a child by using the **IRealTimeStylus::ChildRealTimeStylusPlugin Property** property, no other asynchronous plug-ins can be added to the parent **RealTimeStylus**. The depth and breadth of the chain is limited to one child **RealTimeStylus** object. A child **RealTimeStylus** can have asynchronous plug-ins.

With the exception of [IRealTimeStylus::GetStylusAsyncPluginCount Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getstylusasyncplugincount), the asynchronous plug-in methods, such as [IRealTimeStylus::AddStylusAsyncPlugin Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-addstylusasyncplugin), return E_INVALIDOPERATION when called on a parent [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class).

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::GetStylusAsyncPlugin Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getstylusasyncplugin)

[IRealTimeStylus::RemoveAllStylusAsyncPlugins Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-removeallstylusasyncplugins)

[IRealTimeStylus::RemoveStylusAsyncPlugin Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-removestylusasyncplugin)

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)