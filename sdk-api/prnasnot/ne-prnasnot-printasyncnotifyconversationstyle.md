# PrintAsyncNotifyConversationStyle enumeration

## Description

Specifies whether communication is bidirectional or unidirectional between applications and Print Spooler-hosted components such as printer drivers, print processors, and port monitors.

## Constants

### `kBiDirectional`

Indicates that applications can send replies to the Print Spooler-hosted component that sent a notification.

### `kUniDirectional`

Indicates that communication goes only from the Print Spooler-hosted component to one or more listening applications.

## Remarks

Even when the communication is bidirectional, applications cannot initiate communication. They can only reply to notifications sent by the Print Spooler-hosted components.

When multiple applications listen for bidirectional notifications, they receive only the first notification sent through a bidirectional channel. The Print Spooler maintains the channel only with the first listening application that responded, and discards all subsequent replies from other listeners.