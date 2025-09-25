# SetThreadpoolCallbackPersistent function

## Description

Specifies that the callback should run on a persistent thread.

## Parameters

### `pcbe` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

## Remarks

This function is implemented as an inline function.

To compile an application that uses this function, set _WIN32_WINNT to _WIN32_WINNT_WIN7. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).