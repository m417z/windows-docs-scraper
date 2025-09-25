# RoClearError function

## Description

Removes existing error information from the current thread environment block (TEB).

## Remarks

Call the **RoClearError** function to remove existing thread error information from the thread environment block (TEB). If COM is not initialized, this call does nothing to create the TEB slot for this information. Language projections call this function to ensure there's no stale error information on the thread.