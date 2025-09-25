# SILO_CONTEXT_CLEANUP_CALLBACK callback function

## Description

This callback is invoked when the context object reaches a reference count of zero.

## Parameters

### `SiloContext` [in]

A pointer provided by the user with the call to [PsCreateSiloContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pscreatesilocontext).