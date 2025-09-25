# IAudioProcessingObject::GetLatency

## Description

The GetLatency method returns the latency for this APO. Latency is the amount of time it takes a frame to traverse the processing pass of an APO.

## Parameters

### `pTime` [out]

A pointer to an MFTIME structure that will receive the number of units of delay that this APO introduces. Each unit of delay represents 100 nanoseconds.

## Return value

`GetLatency` returns a value of S_OK if the call was successful. Otherwise, it returns an error code of E_POINTER to indicate that an invalid pointer was passed to the function.

## Remarks

If the client that is calling this APO knows the sampling rate, the client can calculate the latency in terms of the number of frames. To get the total latency of the entire audio signal processing stream, the client must query every APO in the processing chain and add up the results.

**Important** This method is not real-time compliant and must not be called from a real-time processing thread.