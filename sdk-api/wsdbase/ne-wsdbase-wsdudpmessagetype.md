# WSDUdpMessageType enumeration

## Description

Identifies the type of UDP message.

## Constants

### `ONE_WAY:0`

The message is a one-way UDP message without a corresponding response. Hello and Bye messages are one-way messages.

### `TWO_WAY`

The message is a two-way UDP message with a corresponding response. Probe and Resolve messages are two-way messages.