# AdviseInkChange function

## Description

Stops the recognizer from processing ink because a stroke has been added or deleted.

## Parameters

### `hrc`

The handle to the recognizer context.

### `bNewStroke`

**TRUE** if adding a new stroke. Set to **FALSE** if strokes were erased, split, merged, extracted, or deleted from the Ink object.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. This function also returns S_OK if the recognizer does not support this function. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |

## Remarks

The **AdviseInkChange** function signals that there will be additional calls to the [AddStroke](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-addstroke) function. This enables any recognition already in progress to stop at any convenient point. Recognition completion is one such point, so **AdviseInkChange** can safely do nothing.

For example, if you have two threads, one thread may be using [AddStroke](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-addstroke) and [Process](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-process) with other functions to obtain results. The other thread may be collecting ink, echoing it, and queuing tasks for the first thread. The second thread calls **AdviseInkChange** to notify the recognizer a change is coming. This enables the first thread to return to the caller sooner than without the call to **AdviseInkChange**. The first thread can then call the recognizer again with more ink.

If you set the bNewStroke parameter to **FALSE** because a stroke was modified or deleted, you must also call the [ResetContext](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-resetcontext) function, and then call the [AddStroke](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-addstroke) function to add the strokes from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object to the recognizer context. This is done automatically if you attach the recognizer context to the **InkDisp** object.