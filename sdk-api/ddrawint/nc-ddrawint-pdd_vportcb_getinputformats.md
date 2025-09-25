## Description

The **DdVideoPortGetInputFormats** callback function determines the input formats that the DirectDraw VPE object can accept.

## Parameters

### `unnamedParam1`

Points to a [DD_GETVPORTINPUTFORMATDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportinputformatdata) structure that contains the information required for the driver to return the input formats the VPE object can accept.

## Return value

**DdVideoPortGetInputFormats** returns one of the following callback codes:

## Remarks

**DdVideoPortGetInputFormats** must be implemented in DirectDraw drivers that support VPE.

DirectDraw calls **DdVideoPortGetInputFormats** to obtain the number of input formats supported by the specified VPE object and a description of each format. **DdVideoPortGetInputFormats** is called twice for the specified VPE object:

* In the first call, the **lpddpfFormat** member of the DD_GETVPORTINPUTFORMATDATA structure at *lpGetInputFormats* is **NULL**. The driver should write the number of input formats that the VPE object supports in the **dwNumFormats** member of DD_GETVPORTINPUTFORMATDATA. Upon return, DirectDraw will allocate this number of [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structures to pass in the second call to **DdVideoPortGetInputFormats**.
* In the second call, **lpddpfFormat** points to the array of allocated DDPIXELFORMAT structures. The driver should fill in each structure to describe each input format that the VPE object supports. The driver should also return the number of supported input formats in **dwNumFormats**. Note that the driver is guaranteed that the buffer to which **lpddpfFormat** points is large enough to hold the format information being requested.

If the **dwFlags** member of the DD_GETVPORTINPUTFORMATDATA structure is set only to DDVPFORMAT_VIDEO, the driver should return only those formats that are supported for the normal video data. If **dwFlags** is set only to DDVPFORMAT_VBI, the driver should return only those formats supported for the [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data. If **dwFlags** is set to both flags, the driver should return all formats supported by the VPE object.

## See also

[DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat)

[DD_GETVPORTINPUTFORMATDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportinputformatdata)