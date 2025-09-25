# StylusQueue enumeration

## Description

 Specifies the queue to which stylus data is added.

## Constants

### `SyncStylusQueue:0x1`

Data is added to the input queue. When data is added to the input queue, it is automatically added to the output queue.

### `AsyncStylusQueueImmediate:0x2`

Data is added to the output queue. The data is added before any data currently being processed.

### `AsyncStylusQueue:0x3`

Data is added to the output queue.

## Remarks

After the packet data is processed by the synchronous plug-in, it is added to the output queue. The asynchronous plug-in extracts the data from the queue. The amount of data that can be held in the queue is based on the Pen Input Service internal queue and is limited to approximately 10 seconds worth of data. After the queue is full, all successive packets are lost. The queue is used only as a data store. You can process the data from the queue or add your customized data to the queue.

The input queue is an alternative input source for the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object. The Pen Input Service is given priority when the **RealTimeStylus Class** object checks for the next packet data to process. The input queue can be used to send data to all plug-ins while the output queue is used to send data to asynchronous plug-ins only.

The packet data process flow is the following:

1. The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object sends packet data to the synchronous plug-ins.
2. The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object stores the processed packet data in the output queue.
3. The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object checks for pending packet data in the input queue. If there is pending packet data, that packet data is picked up and processed from step 1.
4. The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object checks for any pending packet data from the Pen Input Service. If there is pending packet data, it is picked up and processed from step 1.
5. Repeat steps 3 and 4.

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)

[RealTimeStylus Reference](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-reference)