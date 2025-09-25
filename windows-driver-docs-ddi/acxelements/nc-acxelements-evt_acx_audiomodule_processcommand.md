## Description

The **EVT_ACX_AUDIOMODULE_PROCESSCOMMAND** callback tells the driver to process a command for an audio module element.

## Parameters

### `AudioModule`

An ACXAUDIOMODULE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `InBuffer`

A pointer to the input buffer.

### `InBufferCb`

The input buffer size in count of bytes.

### `OutBuffer`

A pointer to the output buffer.

### `OutBufferCb`

The output buffer size in count of bytes.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_AUDIOMODULE_PROCESSCOMMAND  CodecR_EvtProcessCommand0;

NTSTATUS
CodecR_EvtProcessCommand0(
    _In_    ACXAUDIOMODULE  AudioModule,
    _In_    PVOID           InBuffer,
    _In_    ULONG           InBufferCb,
    _In_    PVOID           OutBuffer,
    _Inout_ PULONG          OutBufferCb
   )
{
    NTSTATUS                        status = STATUS_SUCCESS;
    BOOL                            fNewValue = FALSE;
    PVOID                           currentValue;
    PVOID                           inBuffer = NULL;
    ULONG                           inBufferCb = 0;
    PCODEC_AUDIOMODULE0_CONTEXT     audioModuleCtx;
    AUDIOMODULE_PARAMETER_INFO *    parameterInfo = NULL;
    AUDIOMODULE_CUSTOM_COMMAND *    command = NULL;

    PAGED_CODE();

    audioModuleCtx = GetCodecAudioModule0Context(AudioModule);
    if (audioModuleCtx == NULL)
    {
        ASSERT(FALSE);  // this should not happen.
        status = STATUS_INTERNAL_ERROR;
        goto exit;
    }

    //
    // Basic parameter validation (module specific).
    //
    if (InBuffer == NULL || InBufferCb == 0)
    {
        return STATUS_INVALID_PARAMETER;
    }

    if (InBufferCb < sizeof(AUDIOMODULE_CUSTOM_COMMAND))
    {
        return STATUS_INVALID_PARAMETER;
    }

    command = (AUDIOMODULE_CUSTOM_COMMAND*)InBuffer;

    if (command->ParameterId >= SIZEOF_ARRAY(AudioModule0_ParameterInfo))
    {
        return STATUS_INVALID_PARAMETER;
    }

    //
    // Validate the parameter referenced in the command.
    //
    switch (command->ParameterId)
    {
        case AudioModuleParameter1:
            currentValue = &audioModuleCtx->Parameter1;
            parameterInfo = &AudioModule0_ParameterInfo[AudioModuleParameter1];
            break;
        case AudioModuleParameter2:
            currentValue = &audioModuleCtx->Parameter2;
            parameterInfo = &AudioModule0_ParameterInfo[AudioModuleParameter2];
            break;
        default:
            status = STATUS_INVALID_PARAMETER;
            goto exit;
    }

    //
    // Update input buffer ptr/size.
    //
    inBuffer = (PVOID)((ULONG_PTR)InBuffer + sizeof(AUDIOMODULE_CUSTOM_COMMAND));
    inBufferCb = InBufferCb - sizeof(AUDIOMODULE_CUSTOM_COMMAND);

    if (inBufferCb == 0)
    {
        inBuffer = NULL;
    }

    status = AudioModule_GenericHandler(
                command->Verb,
                command->ParameterId,
                parameterInfo,
                currentValue,
                inBuffer,
                inBufferCb,
                OutBuffer,
                OutBufferCb,
                &fNewValue);

    if (!NT_SUCCESS(status))
    {
        goto exit;
    }

    if (fNewValue &&
        (parameterInfo->Flags & AUDIOMODULE_PARAMETER_FLAG_CHANGE_NOTIFICATION))
    {
        AUDIOMODULE_CUSTOM_NOTIFICATION customNotification = {0};

        customNotification.Type = AudioModuleParameterChanged;
        customNotification.ParameterChanged.ParameterId = command->ParameterId;

        status = AcxPnpEventGenerateEvent(audioModuleCtx->Event, &customNotification, (USHORT)sizeof(customNotification));
        if (!NT_SUCCESS(status))
        {
            goto exit;
        }
    }

    // Normalize error code.
    status = STATUS_SUCCESS;

exit:
    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)