typedef struct sockaddr_atm {
  u_short     satm_family;
  ATM_ADDRESS satm_number;
  ATM_BLLI    satm_blli;
  ATM_BHLI    satm_bhli;
} sockaddr_atm, SOCKADDR_ATM, *PSOCKADDR_ATM, *LPSOCKADDR_ATM;