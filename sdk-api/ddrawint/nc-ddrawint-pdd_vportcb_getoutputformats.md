## Description

The **DdVideoPortGetOutputFormats** callback function determines the output formats that the VPE object supports.

## Parameters

### `unnamedParam1`

Points to a [DD_GETVPORTOUTPUTFORMATDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportoutputformatdata) structure that contains the information required for the driver to return the output formats the VPE object supports.

## Return value

**DdVideoPortGetOutputFormats** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support VPE must implement **DdVideoPortGetOutputFormats**

DirectDraw calls **DdVideoPortGetOutputFormats** to obtain the number of output formats supported by the specified VPE object and a description of each format. **DdVideoPortGetOutputFormats** is called twice for the specified VPE object:

* In the first call, the **lpddpfOutputFormats** member of the DD_GETVPORTOUTPUTFORMATDATA structure at *lpGetOutputFormats* is **NULL**. The driver should write the number of output formats that the VPE object supports in the **dwNumFormats** member of DD_GETVPORTOUTPUTFORMATDATA. Upon return, DirectDraw will allocate this number of [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structures to pass in the second call to **DdVideoPortGetOutputFormats**.
* In the second call, **lpddpfOutputFormats** points to the array of allocated DDPIXELFORMAT structures. The driver should fill in each structure with a description of each output format that the VPE object can write to the frame buffer. The driver should return only those output formats that it supports based on the input format of the video data. The driver should also return the number of supported output formats in **dwNumFormats**. Note that the driver is guaranteed that the buffer to which **lpddpfOutputFormats** points is large enough to hold the format information being requested.

If the **dwFlags** member of DD_GETVPORTOUTPUTFORMATDATA is set only to DDVPFORMAT_VIDEO, the driver should return only those output formats that are supported for normal video data. If **dwFlags** is set only to DDVPFORMAT_VBI, the driver should return only those formats supported for [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data. If **dwFlags** is set to both flags, the driver should return all formats supported by the [VPE](https://learn.microsoft.com/windows-hardware/drivers/) object.

## See also

[DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat)

[DD_GETVPORTOUTPUTFORMATDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportoutputformatdata)