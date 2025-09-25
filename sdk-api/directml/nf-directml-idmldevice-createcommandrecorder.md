# IDMLDevice::CreateCommandRecorder

## Description

Creates a DirectML command recorder.

A command recorder allows your application to record the initialization and execution of compiled operators into
existing Direct3D 12 command lists. The command recorder is a stateless object: it does not own command lists or
operators, nor does it execute any GPU work. Instead, it merely records the commands necessary for
dispatching initialization or execution into an application-supplied command list. Your application is then
responsible for submitting the execution of that command list to the Direct3D 12 command queue.

## Parameters

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *ppv*. This is expected to be the GUID of [IDMLCommandRecorder](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcommandrecorder).

### `ppv` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the command recorder. This is the address of a pointer to an [IDMLCommandRecorder](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcommandrecorder), representing the command recorder created.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)