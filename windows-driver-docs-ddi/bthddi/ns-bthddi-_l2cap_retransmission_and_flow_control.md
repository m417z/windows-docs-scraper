# _L2CAP_RETRANSMISSION_AND_FLOW_CONTROL structure

## Description

The L2CAP_RETRANSMISSION_AND_FLOW_CONTROL structure describes configuration parameters for enhanced retransmission mode and streaming mode.

## Members

### `Mode`

Requested mode for the enhanced L2CAP channel.

### `TxWindowSize`

Size of the transmission window for enhanced retransmission mode. The value of member is valid only when used with enhanced retransmission mode, and is ignored in streaming mode. Valid values range from 1 to 63.

### `MaxTransmit`

Number of times a single I/S frame will be re-transmitted in case of an error. The value of this member is valid only for enhanced retransmission mode and is ignored in streaming mode. The minimum value is 1.

### `RetransmissionTO`

Retransmission timeout value. Profile drivers should set this value to 0.

### `MonitorTO`

Monitor timeout. Profile drivers should set this value to 0.

### `MaxPDUSize`

Maximum PDU Size.