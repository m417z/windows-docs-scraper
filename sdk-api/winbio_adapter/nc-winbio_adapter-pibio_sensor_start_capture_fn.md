# PIBIO_SENSOR_START_CAPTURE_FN callback function

## Description

Called by the Windows Biometric Framework to begin an asynchronous biometric capture.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Purpose` [in]

A **WINBIO_BIR_PURPOSE** bitmask that specifies the intended use of the sample. This can be a bitwise **OR** of the following values:

* WINBIO_PURPOSE_VERIFY
* WINBIO_PURPOSE_IDENTIFY
* WINBIO_PURPOSE_ENROLL
* WINBIO_PURPOSE_ENROLL_FOR_VERIFICATION
* WINBIO_PURPOSE_ENROLL_FOR_IDENTIFICATION

Some sensors have the ability to capture biometric information at multiple resolutions. If the *Purpose* parameter specifies more than one flag, your adapter should use the flag that represents the highest resolution to determine the resolution of the capture operation.

### `Overlapped` [out]

Address of a variable that receives a pointer to an **OVERLAPPED** structure that tracks the state of the asynchronous capture operation. This structure is created and managed by the sensor adapter but is used by the Windows Biometric Framework for synchronization. For more information, see the Remarks section.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. The following values will be recognized by the Windows Biometric Framework.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **E_INVALIDARG** | The *Purpose* parameter is not valid. |
| **E_OUTOFMEMORY** | There was not enough memory to perform the operation. |
| **WINBIO_E_DEVICE_BUSY** | The device is not ready to capture data. |
| **WINBIO_E_DEVICE_FAILURE** | There was a device failure. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is **NULL** or the **SensorHandle** member is set to **INVALID_HANDLE_VALUE**. |

## Remarks

This function does not block. If the adapter issues multiple commands to the sensor to prepare for a capture operation, all but the final command can be synchronous. The final command, issued immediately before *SensorAdapterStartCapture* returns control to the Windows Biometric Framework, must be asynchronous and must use overlapped I/O.

To use overlapped I/O, begin by adding an **OVERLAPPED** object to the definition of the private sensor adapter context structure. This structure is available to the adapter through the **SensorContext** field of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) object.

When you implement [SensorAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_attach_fn), you must perform the following actions to initialize the **OVERLAPPED** structure:

* Clear the **OVERLAPPED** structure by calling the [ZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366920(v=vs.85)) function.
* Create a manual reset event object by using the [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function. It is critical that the event object be manual rather than auto-reset. The use of auto-reset events in overlapped I/O can lead to an unrecoverable lack of response in the I/O processing operation.
* Save the handle of this event in the **hEvent** member of the **OVERLAPPED** structure.

When you implement [SensorAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_detach_fn), you must release the event object by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function. It is important not to release this handle until after all input and output operations related to the capture have been completed or canceled.

The Windows Biometric Framework uses the **OVERLAPPED** object when it calls operating system functions such as [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) and [WaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjects) to determine when the capture operation has completed.

The event handle in the **OVERLAPPED** structure must be in the non-signaled state when *SensorAdapterStartCapture* returns. Calling [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) to start an overlapped I/O operation automatically resets the event. If your adapter uses some other mechanism to start an I/O operation, you must reset the event yourself.

The Windows Biometric Framework guarantees that only one asynchronous I/O operation is outstanding at any time for each biometric unit. Consequently, the sensor adapter only needs one **OVERLAPPED** structure for each processing pipeline.

The Windows Biometric Framework opens and closes the sensor adapter handle and is responsible for ensuring that the handle has been configured for overlapped I/O.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// SensorAdapterStartCapture
//
// Purpose:
//      Begins an asynchronous biometric capture.
//
// Parameters:
//      Pipeline   -  Pointer to a WINBIO_PIPELINE structure associated with
//                    the biometric unit.
//      Purpose    -  A WINBIO_BIR_PURPOSE bitmask that specifies the intended
//                    use of the sample.
//      Overlapped -  Receives a pointer to an OVERLAPPED structure.
//
static HRESULT
WINAPI
SensorAdapterStartCapture(
    __inout PWINBIO_PIPELINE Pipeline,
    __in WINBIO_BIR_PURPOSE Purpose,
    __out LPOVERLAPPED *Overlapped
    )
{
    HRESULT hr = S_OK;
    WINBIO_SENSOR_STATUS sensorStatus = WINBIO_SENSOR_FAILURE;
    WINBIO_CAPTURE_PARAMETERS captureParameters = {0};
    BOOL result = TRUE;
    DWORD bytesReturned = 0;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(Purpose)  ||
        !ARGUMENT_PRESENT(Overlapped))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_SENSOR_CONTEXT sensorContext =
                       (PWINBIO_SENSOR_CONTEXT)Pipeline->SensorContext;

    // Verify the state of the pipeline.
    if (sensorContext == NULL ||
        Pipeline->SensorHandle == INVALID_HANDLE_VALUE)
    {
        return WINBIO_E_INVALID_DEVICE_STATE;
    }

    *Overlapped = NULL;

    //  Synchronously retrieve the status.
    hr = SensorAdapterQueryStatus(Pipeline, &sensorStatus);
    if (FAILED(hr))
    {
        return hr;
    }

    // Determine whether the sensor requires calibration.
    if (sensorStatus == WINBIO_SENSOR_NOT_CALIBRATED)
    {
        // Call a custom function that sends IOCTLs to
        // the sensor to calibrate it. This operation is
        // synchronous.
        hr = _SensorAdapterCalibrate(Pipeline);

        // Retrieve the status again to determine whether the
        // sensor is ready.
        if (SUCCEEDED(hr))
        {
            hr = SensorAdapterQueryStatus(Pipeline, &sensorStatus);
        }

        if (FAILED(hr))
        {
            return hr;
        }
    }
    if (sensorStatus == WINBIO_SENSOR_BUSY)
    {
        return WINBIO_E_DEVICE_BUSY;
    }

    if (sensorStatus != WINBIO_SENSOR_READY)
    {
        return WINBIO_E_INVALID_DEVICE_STATE;
    }

    // Determine whether the data format has been previously determined.
    // If it has not, find a format supported by both the engine and
    // the sensor.
    if ((sensorContext->Format.Owner == 0) &&
        (sensorContext->Format.Type == 0))
    {

        // Retrieve the format preferred by the engine.
        hr = Pipeline->EngineInterface->QueryPreferredFormat(
                                            Pipeline,
                                            &sensorContext->Format,
                                            &sensorContext->VendorFormat
                                            );
        if (SUCCEEDED(hr))
        {
            // Call a private function that queries the sensor driver
            // and attaches an attribute array to the sensor context.
            // This operation is synchronous.
            hr = _SensorAdapterGetAttributes(Pipeline);
        }

        if (SUCCEEDED(hr))
        {
            // Search the sensor attributes array for the format
            // preferred by the engine adapter.
            DWORD i = 0;
            for (i = 0; i < sensorContext->AttributesBuffer->SupportedFormatEntries; i++)
            {
                if ((sensorContext->AttributesBuffer->SupportedFormat[i].Owner == sensorContext->Format.Owner) &&
                    (sensorContext->AttributesBuffer->SupportedFormat[i].Type == sensorContext->Format.Type))
                {
                    break;
                }
            }

            if (i == sensorContext->AttributesBuffer->SupportedFormatEntries)
            {
                // No match was found. Use the default.
                sensorContext->Format.Owner = WINBIO_ANSI_381_FORMAT_OWNER;
                sensorContext->Format.Type = WINBIO_ANSI_381_FORMAT_TYPE;
            }
        }
        else
        {
            return hr;
        }
    }

    // Set up the parameter-input block needed for the IOCTL.
    captureParameters.PayloadSize = sizeof(WINBIO_CAPTURE_PARAMETERS);
    captureParameters.Purpose = Purpose;
    captureParameters.Format.Owner = sensorContext->Format.Owner;
    captureParameters.Format.Type = sensorContext->Format.Type;
    CopyMemory(&captureParameters.VendorFormat, &sensorContext->VendorFormat, sizeof (WINBIO_UUID));
    captureParameters.Flags = WINBIO_DATA_FLAG_RAW;

    // Determine whether a buffer has already been allocated for this sensor.
    if (sensorContext->CaptureBuffer == NULL)
    {
        DWORD allocationSize = 0;

        sensorContext->CaptureBufferSize = 0;

        // This sample assumes that the sensor driver returns
        // a fixed-size DWORD buffer containing the required
        // size of the capture buffer if it receives a buffer
        // that is smaller than sizeof(WINBIO_CAPTURE_DATA).
        //
        // Call the driver with a small buffer to get the
        // allocation size required for this sensor.
        //
        // Because this operation is asynchronous, you must block
        // and wait for it to complete.
        result = DeviceIoControl(
                    Pipeline->SensorHandle,
                    IOCTL_VENDOR_PRIVATE_CMD_CAPTURE_DATA,
                    &captureParameters,
                    sizeof(WINBIO_CAPTURE_PARAMETERS),
                    &allocationSize,
                    sizeof(DWORD),
                    &bytesReturned,
                    &sensorContext->Overlapped
                    );
        if (!result && GetLastError() == ERROR_IO_PENDING)
        {
            SetLastError(ERROR_SUCCESS);

            result = GetOverlappedResult(
                        Pipeline->SensorHandle,
                        &sensorContext->Overlapped,
                        &bytesReturned,
                        TRUE
                        );
        }

        if (!result || bytesReturned != sizeof (DWORD))
        {
            // An error occurred.
            hr = _AdapterGetHresultFromWin32(GetLastError());
            return hr;
        }

        // Make sure that you allocate at least the minimum buffer
        // size needed to get the payload structure.
        if (allocationSize < sizeof(WINBIO_CAPTURE_DATA))
        {
            allocationSize = sizeof(WINBIO_CAPTURE_DATA);
        }

        // Allocate the buffer.
        sensorContext->CaptureBuffer = (PWINBIO_CAPTURE_DATA)_AdapterAlloc(allocationSize);
        if (!sensorContext->CaptureBuffer)
        {
            sensorContext->CaptureBufferSize = 0;
            return E_OUTOFMEMORY;
        }
        sensorContext->CaptureBufferSize = allocationSize;
    }
    else
    {
        // The buffer has already been allocated. Clear the buffer contents.
        SensorAdapterClearContext(Pipeline);
    }

    // Send the capture request. Because this is an asynchronous operation,
    // the IOCTL call will return immediately regardless of
    // whether the I/O has completed.
    result = DeviceIoControl(
                Pipeline->SensorHandle,
                IOCTL_VENDOR_PRIVATE_CMD_CAPTURE_DATA,
                &captureParameters,
                sizeof (WINBIO_CAPTURE_PARAMETERS),
                sensorContext->CaptureBuffer,
                sensorContext->CaptureBufferSize,
                &bytesReturned,
                &sensorContext->Overlapped
                );

    if (result ||
        (!result && GetLastError() == ERROR_IO_PENDING))
    {
        *Overlapped = &sensorContext->Overlapped;
        return S_OK;
    }
    else
    {
        hr = _AdapterGetHresultFromWin32(GetLastError());
        return hr;
    }
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterFinishCapture](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_finish_capture_fn)