# IRDPSRAPIAudioStream::Initialize

## Description

Initializes the audio stream.

## Parameters

### `pnPeriodInHundredNsIntervals` [out]

On return, indicates the stream period in 100 nanosecond intervals. The collaboration sharer calculates how frequently to call the [GetBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiaudiostream-getbuffer) method from this value.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[GetBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiaudiostream-getbuffer)

[IRDPSRAPIAudioStream](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiaudiostream)

[Start](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiaudiostream-start)