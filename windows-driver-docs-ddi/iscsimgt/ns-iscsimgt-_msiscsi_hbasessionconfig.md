# _MSiSCSI_HBASessionConfig structure

## Description

The MSiSCSI_HBASessionConfig structure contains the default logon characteristics that a particular instance of a storage miniport driver uses to create a logon session with a target device.

## Members

### `InitialR2T`

A Boolean value that indicates if the HBA initiator requests permission from the target to transmit unsolicited SCSI data whenever it establishes a new session. If this member is **TRUE**, the HBA initiator requests permission from the target to transmit unsolicited SCSI data whenever it establishes a new session. By default, the initiator does not transmit SCSI data until the target solicits the data by sending a ready-to-transmit (R2T) request, with a buffer offset of 0 and a desired transfer length equal to the minimum of the first burst size and the expected data transfer.

If **InitialR2T** is **TRUE**, the initiator sends a protocol data unit (PDU) to the target with the string "No" in the InitialR2T key of the PDU. The target must respond by sending a PDU to the initiator with the string "No" in the InitialR2T key of the PDU. Both initiator and target must agree before unsolicited data transmission is allowed. Therefore, even if you set **InitialR2T** to **TRUE**, it does not guarantee that the initiator will be able to send unsolicited SCSI data to the target.

If this member is **FALSE**, all sessions that the initiator creates follow the default behavior. For more information about the InitialR2T key, see the *IP Storage Working Group* specification.

### `ImmediateData`

A Boolean value that indicates if the initiator requests permission from the target to transmit immediate data whenever it establishes a new session. If this member is **TRUE**, the initiator requests permission from the target to transmit immediate data whenever it establishes a new session. (*Immediate data* is data that the initiator piggybacks onto an iSCSI command PDU.)

The session's policy with regard to immediate data is determined by a negotiation between the initiator and the target. For more information about how the values in **ImmediateData** and **InitialR2T** affect the negotiation, see the *IP Storage Working Group* specification.

### `MaxRecvDataSegmentLength`

The maximum length, in bytes, of a PDU data segment.

### `MaxBurstLength`

The maximum length, in bytes, of the SCSI data payload in a sequence of input (Data-In) PDUs or solicited output (Data-Out) PDUs.

### `FirstBurstLength`

The maximum amount, in bytes, of unsolicited data that an initiator can send to a target during the execution of a single SCSI command. This amount includes the immediate data, if any, and the sequence of unsolicited Data-Out PDUs, if any, that follow the command.

### `MaxOutstandingR2T`

The maximum number of outstanding R2T requests for each task, excluding the first R2T that initiates the task. An R2T is considered *outstanding* until the last data PDU (with the F bit set to 1) is transferred, or until a sequence reception time-out occurs for that PDU data sequence.

## Remarks

It is optional that you implement this class.

## See also

[MSiSCSI_HBASessionConfig WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-hbasessionconfig-wmi-class)