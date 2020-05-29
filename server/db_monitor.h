#ifndef __DB_MONITOR_H
#define __DB_MONITOR_H

#ifdef __cplusplus
extern "C" {
#endif

void database_init(void);
char *dbserver_image_hdr_mode_get(void);
char *dbserver_image_nr_mode_get(void);
char *dbserver_image_fec_mode_get(void);
void NR_mode_set(char *mode);
void FEC_mode_set(char *mode);

#ifdef __cplusplus
}
#endif

#endif
