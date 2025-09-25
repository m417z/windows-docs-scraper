PFN_WSK_RELEASE_DATAGRAM_INDICATION_LIST PfnWskReleaseDatagramIndicationList;

NTSTATUS PfnWskReleaseDatagramIndicationList(
  [in] PWSK_SOCKET Socket,
  [in] PWSK_DATAGRAM_INDICATION DatagramIndication
)
{...}