# UMS_SYSTEM_THREAD_INFORMATION structure

## Description

Specifies a UMS scheduler thread, UMS worker thread, or non-UMS thread.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Members

### `UmsVersion`

The UMS version.

You must set this member to UMS_VERSION before calling the [GetUmsSystemThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getumssystemthreadinformation) function.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.IsUmsSchedulerThread`

A bitfield that specifies that the thread is a UMS scheduler thread.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.IsUmsWorkerThread`

A bitfield that specifies that the thread is a UMS worker thread.

### `DUMMYUNIONNAME.ThreadUmsFlags`

## Remarks

Used by the [GetUmsSystemThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getumssystemthreadinformation) function.

At most one of **IsUmsSchedulerThread** and **IsUmsWorkerThread** will be set.

If both **IsUmsSchedulerThread** and **IsUmsWorkerThread** are clear then the thread is a non-UMS thread.