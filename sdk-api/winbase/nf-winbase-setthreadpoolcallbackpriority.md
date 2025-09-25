# SetThreadpoolCallbackPriority function

## Description

Specifies the priority of a callback function relative to other work items in the same thread pool.

## Parameters

### `pcbe` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

### `Priority` [in]

The priority for the callback relative to other callbacks in the same thread pool. This parameter can be one of the following **TP_CALLBACK_PRIORITY** enumeration values:

| Value | Meaning |
| --- | --- |
| **TP_CALLBACK_PRIORITY_HIGH** | The callback should run at high priority. |
| **TP_CALLBACK_PRIORITY_LOW** | The callback should run at low priority. |
| **TP_CALLBACK_PRIORITY_NORMAL** | The callback should run at normal priority. |

## Remarks

Higher priority callbacks are guaranteed to be run first by the first available worker thread, but they are not guaranteed to finish before lower priority callbacks.

This function is implemented as an inline function.

To compile an application that uses this function, set _WIN32_WINNT >= _WIN32_WINNT_WIN7. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).