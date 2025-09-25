# _D3DKMT_GETSHAREDRESOURCEADAPTERLUID structure

## Description

Provides information that describes a shared resource and the graphics adapter that the resource was created on.

## Members

### `hGlobalShare` [in]

A handle to the shared resource.

### `hNtHandle` [in]

An NT handle to the process.

### `AdapterLuid` [out]

A LUID that serves as an identifier for the device that the resource indicated by **hGlobalShare** was created on. **LUID** is defined in Dxgi.h.