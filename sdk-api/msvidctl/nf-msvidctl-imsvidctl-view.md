# IMSVidCtl::View

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **View** method configures the Video Control to view an input source, which can be a tune request, a DVD, or a media file.

## Parameters

### `v` [in]

Pointer to the input source as a **VARIANT** type. This parameter must be one of the following:

* A pointer to a valid tune request object that supports the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface. The tune request must be initialized with all the tuning information required for the particular network type.
* The string "DVD:" for DVD playback.
* The name of a media file.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the Video Control already has an active input device, this method configures the device for the specified input. Otherwise, this method locates an input device that can handle the input and activates it.

An input device typically corresponds to a source filter. If the *pv* parameter is a tune request object, the Video Control determines which filter to use by examining the network type on the tune request. For digital television, the input device will be a BDA Network Provider filter. For analog television, it will be a WDM TV Tuner filter. The specific name and implementation of the filter are device-dependent.

After calling **View**, use the following methods to build and run the filter graph:

* The [IMSVidCtl::Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) method builds the rest of the filter graph, based on the selected input and the active features collection. The **Build** method leaves the graph in a stopped state.
* The [IMSVidCtl::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-run) method calls [Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) if the graph is not built, and puts the graph into a running state. When the filter graph runs, the video control starts playing the specified tune request.

If the filter graph is already built and running, an application can call **View** to specify a new tune request, either on the same network type or on a different network type.

If the **View** method succeeds, you can obtain the input device by calling the [IMSVidCtl::get_InputActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_inputactive) method.

You can specify a particular input device by calling the [IMSVidCtl::put_InputActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_inputactive) method and then calling [IMSVidInputDevice::View](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidinputdevice-view) on the device, instead of calling **View** on the Video Control. This might be useful if the local system has multiple devices of the same type. The **View** method is preferred, however, because it automatically locates the correct device type.

#### Examples

The following example shows how to submit a tune request to the Video Control:

```cpp

ITuneRequest *pTuneReq;
/* Obtain the tune request (not shown). */
CComVariant varTuneRequest = pTuneReq;
hr = pVidControl->View(&varTuneRequest);

```

The following example shows how to play a local file:

```cpp

CComVariant varFileName(OLESTR("C:Example.avi"));
hr = pVidControl->View(&varFileName);

```

## See also

[DVD Applications in Visual Basic (Video Control)](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/dvd-applications-in-visual-basic--video-control)

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_InputsAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_inputsavailable)