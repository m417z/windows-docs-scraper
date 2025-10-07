# \_WAVEFORMATEX structure

The **\_WAVEFORMATEX** structure defines the format of waveform-audio data.

## Members

**wFormatTag**

Must be set to a format or formats supported by the device. Note that previous versions of the Windows Media Device Manager recommended using WMDM\_WAVE\_FORMAT\_ALL to indicate support for all formats. However, this is no longer recommended, as different media players will interpret this in different ways, and few devices can truly play any file format. It is now recommended that you use the WMDM\_ENUM\_PROP\_VALID\_VALUES\_ANY value of the [**WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-enum-prop-valid-values-form) enumeration, or better yet specify a range of formats with the [**WMDM\_PROP\_VALUES\_RANGE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-range) structure.

**nChannels**

Number of channels in the waveform-audio data. Monaural data uses one channel, and stereo data uses two channels.

**nSamplesPerSec**

Sample rate, in samples per second (Hertz), at which each channel must be played or recorded. Common values for **nSamplesPerSec** are 8.0 kilohertz (kHz), 11.025 kHz, 22.05 kHz, and 44.1 kHz.

**nAvgBytesPerSec**

Required average data-transfer rate for the format tag, in bytes per second. Playback and recording software can estimate buffer sizes by using the **nAvgBytesPerSec** member.

**nBlockAlign**

Block alignment, in bytes. The block alignment is the minimum atomic unit of data for the **wFormatTag** format type. Playback and recording software must process a multiple of **nBlockAlign** bytes of data at a time. Data written and read from a device must always start at the beginning of a block. For example, it is not possible to correctly start playing PCM data in the middle of a sample (that is, on a boundary that is not block aligned).

**wBitsPerSample**

Bits per sample for the **wFormatTag** format type.

**cbSize**

This member is ignored.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**IMDSPDevice::GetFormatSupport**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-getformatsupport)

[**IMDSPStorage::CreateStorage**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-createstorage)

[**IMDSPStorage::GetAttributes**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getattributes)

[**IWMDMDevice::GetFormatSupport**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getformatsupport)

[**IWMDMOperation::GetObjectAttributes**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-getobjectattributes)

[**IWMDMOperation::SetObjectAttributes**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-setobjectattributes)

[**IWMDMStorage::GetAttributes**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getattributes)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

