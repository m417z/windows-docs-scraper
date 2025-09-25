# IRealTimeStylus::AddCustomStylusDataToQueue

## Description

Adds custom data to the specified queue of the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object.

## Parameters

### `sq` [in]

The [StylusQueue Enumeration](https://learn.microsoft.com/windows/desktop/api/rtscom/ne-rtscom-stylusqueue) specifying the stylus queue to which to add the custom data.

### `pGuidId` [in]

 The GUID for the data to add to the queue specified in *sq*.

### `cbData` [in]

 The size, in chars, of the data that *pbData* points to and which is to be added to the specified queue.

### `pbData` [in]

The custom data to add to the specified queue. May not be **NULL**.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

Specify which queue to add the data to with the *sq* parameter. Identify the data by using its GUID.

The *sq* parameter specifies where to add the custom data. It specifies adding the custom data as one of the following:

* The next packet to be processed in the Input queue.
* A packet to be added to the output queue before the packet currently being processed.
* A packet to be added to the output queue after the packet currently being processed in the queue.

When data is added to the input queue, it is automatically added to the output queue. The order of the inserted data can only be controlled on the output queue by passing **AsyncStylusQueueImmediate** in the *sq* parameter.

The GUID can be used by objects other than plug-ins and real time styluses to add customized information to the queue. This method can be called from any object that has a reference to the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object. The calling object does not have to be a plug-in.

**IRealTimeStylus::AddCustomStylusDataToQueue Method** enables you to add functionality, such as selection and erase.

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)

[StylusQueue Enumeration](https://learn.microsoft.com/windows/desktop/api/rtscom/ne-rtscom-stylusqueue)