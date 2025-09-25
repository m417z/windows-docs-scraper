# HTTP_FLOWRATE_INFO structure

## Description

The transfer rate of a response

## Members

### `Flags`

An [HTTP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_property_flags) structure specifying whether the property is present.

### `MaxBandwidth`

The maximum bandwidth represented in bytes/second. This is the maximum bandwidth for the response after the burst content, whose size is specified in **BurstSize**, has been sent.

### `MaxPeakBandwidth`

The peak bandwidth represented in bytes/second. This is the maximum bandwidth at which the burst is delivered.

### `BurstSize`

The size of the content, in bytes, to be delivered at **MaxPeakBandwidth**. Once this content has been delivered, the response is throttled at **MaxBandwidth**. If the HTTP Server application sends responses at a rate slower than **MaxBandwidth**, the response is subject to burst again at **MaxPeakBandwidth** to maximize bandwidth utilization.

## Remarks

This structure allows an HTTP Server application to maximize the network bandwidth use by throttling down the transfer rate of an HTTP response. This is especially useful in serving media content where the initial burst of the content is served at a higher transfer rate and then throttled. This allows content from a larger number of media to be served concurrently.

The transfer rate is allowed to exceed  **MaxBandwidth** in two cases:

* If the connection slows and the transfer rate falls below  **MaxBandwidth**, the application can go beyond  **MaxBandwidth** to catch up.
* The beginning of a response is allowed to exceed  **MaxBandwidth**. For example, a server may transfer media file at high speed at the beginning in order to expedite playback on the client.
  For example, if that client needs initial 20KB of the file to start playback, the server might have this variable set to 20KB.

When  **MaxBandwidth** is exceeded,  **MaxPeakBandwidth**  is still the absolute upper limit.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)