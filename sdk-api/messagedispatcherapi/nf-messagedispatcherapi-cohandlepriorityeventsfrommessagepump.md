# CoHandlePriorityEventsFromMessagePump function

## Description

Called by message dispatchers on an ASTA thread after dispatching a windows message to provide an opportunity for short-running infrastructural COM calls and other high-priority or short-running COM work to be dispatched between messages. This helps to provide similar responsiveness to these infrastructural calls in an ASTA as in a classic STA, even when there is a long stream of window messages to be handled.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function dispatches any high-priority COM calls or work that are queued on the ASTA thread, then returns. It returns quickly if there is no work to perform.

This function silently does nothing when called on non-ASTA threads.