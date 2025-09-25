# CRYPT_TIMESTAMP_ACCURACY structure

## Description

The **CRYPT_TIMESTAMP_ACCURACY** structure is used by the [CRYPT_TIMESTAMP_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_info) structure to represent the accuracy of the time deviation around the UTC time at which the time stamp token was created by the Time Stamp Authority (TSA).

## Members

### `dwSeconds`

Optional. Specifies, in seconds, the accuracy of the upper limit of the time at which the time stamp token was created by the TSA.

### `dwMillis`

Optional. Specifies, in milliseconds, the accuracy of the upper limit of the time at which the time stamp token was created by the TSA.

### `dwMicros`

Optional. Specifies, in microseconds, the accuracy of the upper limit of the time at which the time-stamp token was created by the TSA.