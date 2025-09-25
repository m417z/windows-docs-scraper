# IXAPO::LockForProcess

## Description

Called by XAudio2 to lock the input and output configurations of an XAPO allowing it to do any final initialization before [Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) is called on the realtime thread.

## Parameters

### `InputLockedParameterCount`

Number of elements in *ppInputLockedParameters*. Must be within the [XAPO_REGISTRATION_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/xapo/ns-xapo-xapo_registration_properties).MinInputBufferCount and **XAPO_REGISTRATION_PROPERTIES**.MaxInputBufferCount values passed to [CXAPOBase::CXAPOBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nf-xapobase-cxapobase-cxapobase).

### `pInputLockedParameters`

Array of input [XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS](https://learn.microsoft.com/windows/win32/api/xapo/ns-xapo-xapo_lockforprocess_parameters) structures. *pInputLockedParameters* may be NULL if *InputLockedParameterCount* is 0, otherwise it must have *InputLockedParameterCount* elements.

### `OutputLockedParameterCount`

Number of elements in ppOutputLockedParameters. Must be within the [XAPO_REGISTRATION_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/xapo/ns-xapo-xapo_registration_properties).MinOutputBufferCount and **XAPO_REGISTRATION_PROPERTIES**.MaxOutputBufferCount values passed to [CXAPOBase::CXAPOBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nf-xapobase-cxapobase-cxapobase). If the XAPO_FLAG_BUFFERCOUNT_MUST_MATCH flag was specified in **XAPO_REGISTRATION_PROPERTIES**.Flags then *OutputLockedParameterCount* must equal *InputLockedParameterCount*.

### `pOutputLockedParameters`

Array of output [XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS](https://learn.microsoft.com/windows/win32/api/xapo/ns-xapo-xapo_lockforprocess_parameters) structures. *pOutputLockedParameters* may be NULL if *OutputLockedParameterCount* is 0, otherwise it must have *OutputLockedParameterCount* elements.

## Return value

Returns S_OK if successful, an error code otherwise.

## Remarks

Once locked, the input and output configuration and any other locked parameters remain constant until [UnLockForProcess](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-unlockforprocess) is called. After an XAPO is locked, further calls to **LockForProcess** have no effect until the **UnLockForProcess** function is called.

An XAPO indicates what specific formats it supports through its implementation of the [IsInputFormatSupported](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-isinputformatsupported) and [IsOutputFormatSupported](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-isoutputformatsupported) methods. An XAPO should assert the input and output configurations are supported and that any required effect-specific initialization is complete. The **IsInputFormatSupported**, **IsOutputFormatSupported**, and [Initialize](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-initialize) methods should be used as necessary before calling this method.

Because [Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) is a nonblocking method, all internal memory buffers required for **Process** should be allocated in **LockForProcess**.

[Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) is never called before **LockForProcess** returns successfully.

**LockForProcess** is called directly by XAudio2 and should not be called by the client code.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)