# _MSiSCSI_MMIPSECStats structure

## Description

The MSiSCSI_MMIPSECStats structure is used to report main mode IPsec statistics.

## Members

### `ActiveAcquire`

The number of active require requests that the IPsec driver has sent to the Internet Key Exchange (IKE) service. Typically, the number of active acquire requests is 1. Under a heavy load, the number of active acquire requests is 1 plus the number of requests that are waiting in the queue of the IKE service.

### `ActiveReceive`

The number of IKE messages (that is, active receive requests) that are queued for processing.

### `AcquireFailures`

The number of active acquire requests that have failed.

### `ReceiveFailures`

The number of failures that have occurred while drivers in the TCP stack are receiving IKE messages.

### `SendFailures`

The number of failures that have occurred while drivers in the TCP stack are sending IKE messages.

### `AcquireHeapSize`

The number of IKE messages that the acquire heap can hold. This number increases under a heavy load and then gradually decreases over time, as the acquire heap is emptied.

### `ReceiveHeapSize`

The number of incoming IKE messages that the IKE receive buffers can hold.

### `NegotiationFailures`

The total number of negotiation failures that occurred during main mode (also known as *phase 1*) negotiation or during quick mode (also known as *phase 2*) negotiation.

### `AuthenticationFailures`

The number of identity authentication failures that occurred during main mode negotiation. This number includes kerberos failures, certificate failures, and preshared key failures.

### `InvalidCookiesReceived`

The number of invalid cookies that the initiator has received in IKE messages. Cookies are invalid if the cookie state does not correspond to the state of an active main mode security association (SA).

### `TotalGetSPI`

The number of requests that the IKE service submitted to obtain a unique security parameters index (SPI).

### `KeyAdditions`

The number of outbound quick mode SAs that the IKE service has added.

### `KeyUpdates`

The number of inbound quick mode SAs that the IKE service has added.

### `GetSPIFailures`

The total number of unsuccessful attempts that the IKE service has made to obtain a unique SPI.

### `KeyAdditionFailures`

The number of outbound quick-mode SAs that the IKE service has submitted unsuccessfully.

### `KeyUpdateFailures`

The number of inbound quick-mode SAs that the IKE service has added.

### `ConnectionListSize`

The number of quick-mode state entries.

### `OakleyMainMode`

The number of successful SAs that are created during main mode negotiations.

### `OakleyQuickMode`

The number of successful SAs that are created during quick-mode negotiations.

### `InvalidPackets`

The number of received IKE messages that are invalid, including IKE messages with invalid header fields, incorrect payload lengths, or incorrect (nonzero) responder cookies that should be 0.

### `SoftAssociations`

The number of negotiations that resulted in the use of plaintext SAs (also known as *soft SAs*). This value typically reflects the number of associations that the initiator established with computers that did not respond to main mode negotiation attempts. Computers that do not respond might not support IPSec, or they might support IPSec but not have an IPSec policy with which to negotiate security with an IPSec peer.

## Remarks

It is optional that you implement this class.

## See also

[MSiSCSI_MMIPSECStats WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-mmipsecstats-wmi-class)