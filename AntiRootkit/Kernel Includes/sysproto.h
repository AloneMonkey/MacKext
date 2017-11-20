#ifndef inficere_sysproto_h
#define inficere_sysproto_h

#include <sys/appleapiopts.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <mach/shared_region.h>
#include <sys/socket.h>

/*
 * The kernel may support multiple userspace ABIs, and must use
 * argument structures with elements large enough for any of them.
 */

#ifndef __arm__
#define	PAD_(t)	(sizeof(uint64_t) <= sizeof(t) ? 0 : sizeof(uint64_t) - sizeof(t))
#else
#define	PAD_(t)	(sizeof(uint32_t) <= sizeof(t) ? 0 : sizeof(uint32_t) - sizeof(t))
#endif

#if BYTE_ORDER == LITTLE_ENDIAN
#define	PADL_(t)	0
#define	PADR_(t)	PAD_(t)
#else
#define	PADL_(t)	PAD_(t)
#define	PADR_(t)	0
#endif

struct nosys_args {
	int32_t dummy;
};
struct exit_args {
	char rval_l_[PADL_(int)]; int rval; char rval_r_[PADR_(int)];
};
struct fork_args {
	int32_t dummy;
};
struct read_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char cbuf_l_[PADL_(user_addr_t)]; user_addr_t cbuf; char cbuf_r_[PADR_(user_addr_t)];
	char nbyte_l_[PADL_(user_size_t)]; user_size_t nbyte; char nbyte_r_[PADR_(user_size_t)];
};
struct write_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char cbuf_l_[PADL_(user_addr_t)]; user_addr_t cbuf; char cbuf_r_[PADR_(user_addr_t)];
	char nbyte_l_[PADL_(user_size_t)]; user_size_t nbyte; char nbyte_r_[PADR_(user_size_t)];
};
struct open_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
};
struct close_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
};
struct wait4_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
	char status_l_[PADL_(user_addr_t)]; user_addr_t status; char status_r_[PADR_(user_addr_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
	char rusage_l_[PADL_(user_addr_t)]; user_addr_t rusage; char rusage_r_[PADR_(user_addr_t)];
};
struct link_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char link_l_[PADL_(user_addr_t)]; user_addr_t link; char link_r_[PADR_(user_addr_t)];
};
struct unlink_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct chdir_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct fchdir_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
};
struct mknod_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char dev_l_[PADL_(int)]; int dev; char dev_r_[PADR_(int)];
};
struct chmod_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
};
struct chown_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char uid_l_[PADL_(int)]; int uid; char uid_r_[PADR_(int)];
	char gid_l_[PADL_(int)]; int gid; char gid_r_[PADR_(int)];
};
struct getfsstat_args {
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(int)]; int bufsize; char bufsize_r_[PADR_(int)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct getpid_args {
	int32_t dummy;
};
struct setuid_args {
	char uid_l_[PADL_(uid_t)]; uid_t uid; char uid_r_[PADR_(uid_t)];
};
struct getuid_args {
	int32_t dummy;
};
struct geteuid_args {
	int32_t dummy;
};
struct ptrace_args {
	char req_l_[PADL_(int)]; int req; char req_r_[PADR_(int)];
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char data_l_[PADL_(int)]; int data; char data_r_[PADR_(int)];
};
struct recvmsg_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char msg_l_[PADL_(user_addr_t)]; user_addr_t msg; char msg_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct sendmsg_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char msg_l_[PADL_(user_addr_t)]; user_addr_t msg; char msg_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct recvfrom_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char from_l_[PADL_(user_addr_t)]; user_addr_t from; char from_r_[PADR_(user_addr_t)];
	char fromlenaddr_l_[PADL_(user_addr_t)]; user_addr_t fromlenaddr; char fromlenaddr_r_[PADR_(user_addr_t)];
};
struct accept_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
	char anamelen_l_[PADL_(user_addr_t)]; user_addr_t anamelen; char anamelen_r_[PADR_(user_addr_t)];
};
struct getpeername_args {
	char fdes_l_[PADL_(int)]; int fdes; char fdes_r_[PADR_(int)];
	char asa_l_[PADL_(user_addr_t)]; user_addr_t asa; char asa_r_[PADR_(user_addr_t)];
	char alen_l_[PADL_(user_addr_t)]; user_addr_t alen; char alen_r_[PADR_(user_addr_t)];
};
struct getsockname_args {
	char fdes_l_[PADL_(int)]; int fdes; char fdes_r_[PADR_(int)];
	char asa_l_[PADL_(user_addr_t)]; user_addr_t asa; char asa_r_[PADR_(user_addr_t)];
	char alen_l_[PADL_(user_addr_t)]; user_addr_t alen; char alen_r_[PADR_(user_addr_t)];
};
struct access_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct chflags_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct fchflags_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct sync_args {
	int32_t dummy;
};
struct kill_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
	char signum_l_[PADL_(int)]; int signum; char signum_r_[PADR_(int)];
	char posix_l_[PADL_(int)]; int posix; char posix_r_[PADR_(int)];
};
struct getppid_args {
	int32_t dummy;
};
struct dup_args {
	char fd_l_[PADL_(u_int)]; u_int fd; char fd_r_[PADR_(u_int)];
};
struct pipe_args {
	int32_t dummy;
};
struct getegid_args {
	int32_t dummy;
};
struct profil_args {
	char bufbase_l_[PADL_(user_addr_t)]; user_addr_t bufbase; char bufbase_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(user_size_t)]; user_size_t bufsize; char bufsize_r_[PADR_(user_size_t)];
	char pcoffset_l_[PADL_(user_ulong_t)]; user_ulong_t pcoffset; char pcoffset_r_[PADR_(user_ulong_t)];
	char pcscale_l_[PADL_(u_int)]; u_int pcscale; char pcscale_r_[PADR_(u_int)];
};
struct sigaction_args {
	char signum_l_[PADL_(int)]; int signum; char signum_r_[PADR_(int)];
	char nsa_l_[PADL_(user_addr_t)]; user_addr_t nsa; char nsa_r_[PADR_(user_addr_t)];
	char osa_l_[PADL_(user_addr_t)]; user_addr_t osa; char osa_r_[PADR_(user_addr_t)];
};
struct getgid_args {
	int32_t dummy;
};
struct sigprocmask_args {
	char how_l_[PADL_(int)]; int how; char how_r_[PADR_(int)];
	char mask_l_[PADL_(user_addr_t)]; user_addr_t mask; char mask_r_[PADR_(user_addr_t)];
	char omask_l_[PADL_(user_addr_t)]; user_addr_t omask; char omask_r_[PADR_(user_addr_t)];
};
struct getlogin_args {
	char namebuf_l_[PADL_(user_addr_t)]; user_addr_t namebuf; char namebuf_r_[PADR_(user_addr_t)];
	char namelen_l_[PADL_(u_int)]; u_int namelen; char namelen_r_[PADR_(u_int)];
};
struct setlogin_args {
	char namebuf_l_[PADL_(user_addr_t)]; user_addr_t namebuf; char namebuf_r_[PADR_(user_addr_t)];
};
struct acct_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct sigpending_args {
	char osv_l_[PADL_(user_addr_t)]; user_addr_t osv; char osv_r_[PADR_(user_addr_t)];
};
struct sigaltstack_args {
	char nss_l_[PADL_(user_addr_t)]; user_addr_t nss; char nss_r_[PADR_(user_addr_t)];
	char oss_l_[PADL_(user_addr_t)]; user_addr_t oss; char oss_r_[PADR_(user_addr_t)];
};
struct ioctl_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char com_l_[PADL_(user_ulong_t)]; user_ulong_t com; char com_r_[PADR_(user_ulong_t)];
	char data_l_[PADL_(user_addr_t)]; user_addr_t data; char data_r_[PADR_(user_addr_t)];
};
struct reboot_args {
	char opt_l_[PADL_(int)]; int opt; char opt_r_[PADR_(int)];
	char command_l_[PADL_(user_addr_t)]; user_addr_t command; char command_r_[PADR_(user_addr_t)];
};
struct revoke_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct symlink_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char link_l_[PADL_(user_addr_t)]; user_addr_t link; char link_r_[PADR_(user_addr_t)];
};
struct readlink_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char count_l_[PADL_(int)]; int count; char count_r_[PADR_(int)];
};
struct execve_args {
	char fname_l_[PADL_(user_addr_t)]; user_addr_t fname; char fname_r_[PADR_(user_addr_t)];
	char argp_l_[PADL_(user_addr_t)]; user_addr_t argp; char argp_r_[PADR_(user_addr_t)];
	char envp_l_[PADL_(user_addr_t)]; user_addr_t envp; char envp_r_[PADR_(user_addr_t)];
};
struct umask_args {
	char newmask_l_[PADL_(int)]; int newmask; char newmask_r_[PADR_(int)];
};
struct chroot_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct msync_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct vfork_args {
	int32_t dummy;
};
struct munmap_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
};
struct mprotect_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char prot_l_[PADL_(int)]; int prot; char prot_r_[PADR_(int)];
};
struct madvise_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char behav_l_[PADL_(int)]; int behav; char behav_r_[PADR_(int)];
};
struct mincore_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char vec_l_[PADL_(user_addr_t)]; user_addr_t vec; char vec_r_[PADR_(user_addr_t)];
};
struct getgroups_args {
	char gidsetsize_l_[PADL_(u_int)]; u_int gidsetsize; char gidsetsize_r_[PADR_(u_int)];
	char gidset_l_[PADL_(user_addr_t)]; user_addr_t gidset; char gidset_r_[PADR_(user_addr_t)];
};
struct setgroups_args {
	char gidsetsize_l_[PADL_(u_int)]; u_int gidsetsize; char gidsetsize_r_[PADR_(u_int)];
	char gidset_l_[PADL_(user_addr_t)]; user_addr_t gidset; char gidset_r_[PADR_(user_addr_t)];
};
struct getpgrp_args {
	int32_t dummy;
};
struct setpgid_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
	char pgid_l_[PADL_(int)]; int pgid; char pgid_r_[PADR_(int)];
};
struct setitimer_args {
	char which_l_[PADL_(u_int)]; u_int which; char which_r_[PADR_(u_int)];
	char itv_l_[PADL_(user_addr_t)]; user_addr_t itv; char itv_r_[PADR_(user_addr_t)];
	char oitv_l_[PADL_(user_addr_t)]; user_addr_t oitv; char oitv_r_[PADR_(user_addr_t)];
};
struct swapon_args {
	int32_t dummy;
};
struct getitimer_args {
	char which_l_[PADL_(u_int)]; u_int which; char which_r_[PADR_(u_int)];
	char itv_l_[PADL_(user_addr_t)]; user_addr_t itv; char itv_r_[PADR_(user_addr_t)];
};
struct getdtablesize_args {
	int32_t dummy;
};
struct dup2_args {
	char from_l_[PADL_(u_int)]; u_int from; char from_r_[PADR_(u_int)];
	char to_l_[PADL_(u_int)]; u_int to; char to_r_[PADR_(u_int)];
};
struct fcntl_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char arg_l_[PADL_(user_long_t)]; user_long_t arg; char arg_r_[PADR_(user_long_t)];
};
struct select_args {
	char nd_l_[PADL_(int)]; int nd; char nd_r_[PADR_(int)];
	char in_l_[PADL_(user_addr_t)]; user_addr_t in; char in_r_[PADR_(user_addr_t)];
	char ou_l_[PADL_(user_addr_t)]; user_addr_t ou; char ou_r_[PADR_(user_addr_t)];
	char ex_l_[PADL_(user_addr_t)]; user_addr_t ex; char ex_r_[PADR_(user_addr_t)];
	char tv_l_[PADL_(user_addr_t)]; user_addr_t tv; char tv_r_[PADR_(user_addr_t)];
};
struct fsync_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
};
struct setpriority_args {
	char which_l_[PADL_(int)]; int which; char which_r_[PADR_(int)];
	char who_l_[PADL_(id_t)]; id_t who; char who_r_[PADR_(id_t)];
	char prio_l_[PADL_(int)]; int prio; char prio_r_[PADR_(int)];
};
struct socket_args {
	char domain_l_[PADL_(int)]; int domain; char domain_r_[PADR_(int)];
	char type_l_[PADL_(int)]; int type; char type_r_[PADR_(int)];
	char protocol_l_[PADL_(int)]; int protocol; char protocol_r_[PADR_(int)];
};
struct connect_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
	char namelen_l_[PADL_(socklen_t)]; socklen_t namelen; char namelen_r_[PADR_(socklen_t)];
};
struct getpriority_args {
	char which_l_[PADL_(int)]; int which; char which_r_[PADR_(int)];
	char who_l_[PADL_(id_t)]; id_t who; char who_r_[PADR_(id_t)];
};
struct bind_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
	char namelen_l_[PADL_(socklen_t)]; socklen_t namelen; char namelen_r_[PADR_(socklen_t)];
};
struct setsockopt_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char level_l_[PADL_(int)]; int level; char level_r_[PADR_(int)];
	char name_l_[PADL_(int)]; int name; char name_r_[PADR_(int)];
	char val_l_[PADL_(user_addr_t)]; user_addr_t val; char val_r_[PADR_(user_addr_t)];
	char valsize_l_[PADL_(socklen_t)]; socklen_t valsize; char valsize_r_[PADR_(socklen_t)];
};
struct listen_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char backlog_l_[PADL_(int)]; int backlog; char backlog_r_[PADR_(int)];
};
struct sigsuspend_args {
	char mask_l_[PADL_(sigset_t)]; sigset_t mask; char mask_r_[PADR_(sigset_t)];
};
struct gettimeofday_args {
	char tp_l_[PADL_(user_addr_t)]; user_addr_t tp; char tp_r_[PADR_(user_addr_t)];
	char tzp_l_[PADL_(user_addr_t)]; user_addr_t tzp; char tzp_r_[PADR_(user_addr_t)];
};
struct getrusage_args {
	char who_l_[PADL_(int)]; int who; char who_r_[PADR_(int)];
	char rusage_l_[PADL_(user_addr_t)]; user_addr_t rusage; char rusage_r_[PADR_(user_addr_t)];
};
struct getsockopt_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char level_l_[PADL_(int)]; int level; char level_r_[PADR_(int)];
	char name_l_[PADL_(int)]; int name; char name_r_[PADR_(int)];
	char val_l_[PADL_(user_addr_t)]; user_addr_t val; char val_r_[PADR_(user_addr_t)];
	char avalsize_l_[PADL_(user_addr_t)]; user_addr_t avalsize; char avalsize_r_[PADR_(user_addr_t)];
};
struct readv_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char iovp_l_[PADL_(user_addr_t)]; user_addr_t iovp; char iovp_r_[PADR_(user_addr_t)];
	char iovcnt_l_[PADL_(u_int)]; u_int iovcnt; char iovcnt_r_[PADR_(u_int)];
};
struct writev_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char iovp_l_[PADL_(user_addr_t)]; user_addr_t iovp; char iovp_r_[PADR_(user_addr_t)];
	char iovcnt_l_[PADL_(u_int)]; u_int iovcnt; char iovcnt_r_[PADR_(u_int)];
};
struct settimeofday_args {
	char tv_l_[PADL_(user_addr_t)]; user_addr_t tv; char tv_r_[PADR_(user_addr_t)];
	char tzp_l_[PADL_(user_addr_t)]; user_addr_t tzp; char tzp_r_[PADR_(user_addr_t)];
};
struct fchown_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char uid_l_[PADL_(int)]; int uid; char uid_r_[PADR_(int)];
	char gid_l_[PADL_(int)]; int gid; char gid_r_[PADR_(int)];
};
struct fchmod_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
};
struct setreuid_args {
	char ruid_l_[PADL_(uid_t)]; uid_t ruid; char ruid_r_[PADR_(uid_t)];
	char euid_l_[PADL_(uid_t)]; uid_t euid; char euid_r_[PADR_(uid_t)];
};
struct setregid_args {
	char rgid_l_[PADL_(gid_t)]; gid_t rgid; char rgid_r_[PADR_(gid_t)];
	char egid_l_[PADL_(gid_t)]; gid_t egid; char egid_r_[PADR_(gid_t)];
};
struct rename_args {
	char from_l_[PADL_(user_addr_t)]; user_addr_t from; char from_r_[PADR_(user_addr_t)];
	char to_l_[PADL_(user_addr_t)]; user_addr_t to; char to_r_[PADR_(user_addr_t)];
};
struct flock_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char how_l_[PADL_(int)]; int how; char how_r_[PADR_(int)];
};
struct mkfifo_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
};
struct sendto_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char to_l_[PADL_(user_addr_t)]; user_addr_t to; char to_r_[PADR_(user_addr_t)];
	char tolen_l_[PADL_(socklen_t)]; socklen_t tolen; char tolen_r_[PADR_(socklen_t)];
};
struct shutdown_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char how_l_[PADL_(int)]; int how; char how_r_[PADR_(int)];
};
struct socketpair_args {
	char domain_l_[PADL_(int)]; int domain; char domain_r_[PADR_(int)];
	char type_l_[PADL_(int)]; int type; char type_r_[PADR_(int)];
	char protocol_l_[PADL_(int)]; int protocol; char protocol_r_[PADR_(int)];
	char rsv_l_[PADL_(user_addr_t)]; user_addr_t rsv; char rsv_r_[PADR_(user_addr_t)];
};
struct mkdir_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
};
struct rmdir_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct utimes_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char tptr_l_[PADL_(user_addr_t)]; user_addr_t tptr; char tptr_r_[PADR_(user_addr_t)];
};
struct futimes_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char tptr_l_[PADL_(user_addr_t)]; user_addr_t tptr; char tptr_r_[PADR_(user_addr_t)];
};
struct adjtime_args {
	char delta_l_[PADL_(user_addr_t)]; user_addr_t delta; char delta_r_[PADR_(user_addr_t)];
	char olddelta_l_[PADL_(user_addr_t)]; user_addr_t olddelta; char olddelta_r_[PADR_(user_addr_t)];
};
struct gethostuuid_args {
	char uuid_buf_l_[PADL_(user_addr_t)]; user_addr_t uuid_buf; char uuid_buf_r_[PADR_(user_addr_t)];
	char timeoutp_l_[PADL_(user_addr_t)]; user_addr_t timeoutp; char timeoutp_r_[PADR_(user_addr_t)];
};
struct setsid_args {
	int32_t dummy;
};
struct getpgid_args {
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
};
struct setprivexec_args {
	char flag_l_[PADL_(int)]; int flag; char flag_r_[PADR_(int)];
};
struct pread_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char nbyte_l_[PADL_(user_size_t)]; user_size_t nbyte; char nbyte_r_[PADR_(user_size_t)];
	char offset_l_[PADL_(off_t)]; off_t offset; char offset_r_[PADR_(off_t)];
};
struct pwrite_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char nbyte_l_[PADL_(user_size_t)]; user_size_t nbyte; char nbyte_r_[PADR_(user_size_t)];
	char offset_l_[PADL_(off_t)]; off_t offset; char offset_r_[PADR_(off_t)];
};
struct nfssvc_args {
	char flag_l_[PADL_(int)]; int flag; char flag_r_[PADR_(int)];
	char argp_l_[PADL_(user_addr_t)]; user_addr_t argp; char argp_r_[PADR_(user_addr_t)];
};
struct statfs_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
};
struct fstatfs_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
};
struct unmount_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct getfh_args {
	char fname_l_[PADL_(user_addr_t)]; user_addr_t fname; char fname_r_[PADR_(user_addr_t)];
	char fhp_l_[PADL_(user_addr_t)]; user_addr_t fhp; char fhp_r_[PADR_(user_addr_t)];
};
struct quotactl_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char uid_l_[PADL_(int)]; int uid; char uid_r_[PADR_(int)];
	char arg_l_[PADL_(user_addr_t)]; user_addr_t arg; char arg_r_[PADR_(user_addr_t)];
};
struct mount_args {
	char type_l_[PADL_(user_addr_t)]; user_addr_t type; char type_r_[PADR_(user_addr_t)];
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char data_l_[PADL_(user_addr_t)]; user_addr_t data; char data_r_[PADR_(user_addr_t)];
};
struct csops_args {
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
	char ops_l_[PADL_(uint32_t)]; uint32_t ops; char ops_r_[PADR_(uint32_t)];
	char useraddr_l_[PADL_(user_addr_t)]; user_addr_t useraddr; char useraddr_r_[PADR_(user_addr_t)];
	char usersize_l_[PADL_(user_size_t)]; user_size_t usersize; char usersize_r_[PADR_(user_size_t)];
};
/*
 struct waitid_args {
 char idtype_l_[PADL_(idtype_t)]; idtype_t idtype; char idtype_r_[PADR_(idtype_t)];
 char id_l_[PADL_(id_t)]; id_t id; char id_r_[PADR_(id_t)];
 char infop_l_[PADL_(user_addr_t)]; user_addr_t infop; char infop_r_[PADR_(user_addr_t)];
 char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
 };
 */
struct add_profil_args {
	char bufbase_l_[PADL_(user_addr_t)]; user_addr_t bufbase; char bufbase_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(user_size_t)]; user_size_t bufsize; char bufsize_r_[PADR_(user_size_t)];
	char pcoffset_l_[PADL_(user_ulong_t)]; user_ulong_t pcoffset; char pcoffset_r_[PADR_(user_ulong_t)];
	char pcscale_l_[PADL_(u_int)]; u_int pcscale; char pcscale_r_[PADR_(u_int)];
};
struct kdebug_trace_args {
	char code_l_[PADL_(int)]; int code; char code_r_[PADR_(int)];
	char arg1_l_[PADL_(int)]; int arg1; char arg1_r_[PADR_(int)];
	char arg2_l_[PADL_(int)]; int arg2; char arg2_r_[PADR_(int)];
	char arg3_l_[PADL_(int)]; int arg3; char arg3_r_[PADR_(int)];
	char arg4_l_[PADL_(int)]; int arg4; char arg4_r_[PADR_(int)];
	char arg5_l_[PADL_(int)]; int arg5; char arg5_r_[PADR_(int)];
};
struct setgid_args {
	char gid_l_[PADL_(gid_t)]; gid_t gid; char gid_r_[PADR_(gid_t)];
};
struct setegid_args {
	char egid_l_[PADL_(gid_t)]; gid_t egid; char egid_r_[PADR_(gid_t)];
};
struct seteuid_args {
	char euid_l_[PADL_(uid_t)]; uid_t euid; char euid_r_[PADR_(uid_t)];
};
struct sigreturn_args {
	char uctx_l_[PADL_(user_addr_t)]; user_addr_t uctx; char uctx_r_[PADR_(user_addr_t)];
	char infostyle_l_[PADL_(int)]; int infostyle; char infostyle_r_[PADR_(int)];
};
struct chud_args {
	char code_l_[PADL_(uint64_t)]; uint64_t code; char code_r_[PADR_(uint64_t)];
	char arg1_l_[PADL_(uint64_t)]; uint64_t arg1; char arg1_r_[PADR_(uint64_t)];
	char arg2_l_[PADL_(uint64_t)]; uint64_t arg2; char arg2_r_[PADR_(uint64_t)];
	char arg3_l_[PADL_(uint64_t)]; uint64_t arg3; char arg3_r_[PADR_(uint64_t)];
	char arg4_l_[PADL_(uint64_t)]; uint64_t arg4; char arg4_r_[PADR_(uint64_t)];
	char arg5_l_[PADL_(uint64_t)]; uint64_t arg5; char arg5_r_[PADR_(uint64_t)];
};
struct fdatasync_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
};
struct stat_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
};
struct fstat_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
};
struct lstat_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
};
struct pathconf_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char name_l_[PADL_(int)]; int name; char name_r_[PADR_(int)];
};
struct fpathconf_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char name_l_[PADL_(int)]; int name; char name_r_[PADR_(int)];
};
struct getrlimit_args {
	char which_l_[PADL_(u_int)]; u_int which; char which_r_[PADR_(u_int)];
	char rlp_l_[PADL_(user_addr_t)]; user_addr_t rlp; char rlp_r_[PADR_(user_addr_t)];
};
struct setrlimit_args {
	char which_l_[PADL_(u_int)]; u_int which; char which_r_[PADR_(u_int)];
	char rlp_l_[PADL_(user_addr_t)]; user_addr_t rlp; char rlp_r_[PADR_(user_addr_t)];
};
struct getdirentries_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char count_l_[PADL_(u_int)]; u_int count; char count_r_[PADR_(u_int)];
	char basep_l_[PADL_(user_addr_t)]; user_addr_t basep; char basep_r_[PADR_(user_addr_t)];
};
struct mmap_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char prot_l_[PADL_(int)]; int prot; char prot_r_[PADR_(int)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char pos_l_[PADL_(off_t)]; off_t pos; char pos_r_[PADR_(off_t)];
};
struct lseek_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char offset_l_[PADL_(off_t)]; off_t offset; char offset_r_[PADR_(off_t)];
	char whence_l_[PADL_(int)]; int whence; char whence_r_[PADR_(int)];
};
struct truncate_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char length_l_[PADL_(off_t)]; off_t length; char length_r_[PADR_(off_t)];
};
struct ftruncate_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char length_l_[PADL_(off_t)]; off_t length; char length_r_[PADR_(off_t)];
};
struct __sysctl_args {
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
	char namelen_l_[PADL_(u_int)]; u_int namelen; char namelen_r_[PADR_(u_int)];
	char old_l_[PADL_(user_addr_t)]; user_addr_t old; char old_r_[PADR_(user_addr_t)];
	char oldlenp_l_[PADL_(user_addr_t)]; user_addr_t oldlenp; char oldlenp_r_[PADR_(user_addr_t)];
	char new_l_[PADL_(user_addr_t)]; user_addr_t new; char new_r_[PADR_(user_addr_t)];
	char newlen_l_[PADL_(user_size_t)]; user_size_t newlen; char newlen_r_[PADR_(user_size_t)];
};
struct mlock_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
};
struct munlock_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
};
struct undelete_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct ATsocket_args {
	char proto_l_[PADL_(int)]; int proto; char proto_r_[PADR_(int)];
};
struct ATgetmsg_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char ctlptr_l_[PADL_(void *)]; void * ctlptr; char ctlptr_r_[PADR_(void *)];
	char datptr_l_[PADL_(void *)]; void * datptr; char datptr_r_[PADR_(void *)];
	char flags_l_[PADL_(int *)]; int * flags; char flags_r_[PADR_(int *)];
};
struct ATputmsg_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char ctlptr_l_[PADL_(void *)]; void * ctlptr; char ctlptr_r_[PADR_(void *)];
	char datptr_l_[PADL_(void *)]; void * datptr; char datptr_r_[PADR_(void *)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct ATPsndreq_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(unsigned char *)]; unsigned char * buf; char buf_r_[PADR_(unsigned char *)];
	char len_l_[PADL_(int)]; int len; char len_r_[PADR_(int)];
	char nowait_l_[PADL_(int)]; int nowait; char nowait_r_[PADR_(int)];
};
struct ATPsndrsp_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char respbuff_l_[PADL_(unsigned char *)]; unsigned char * respbuff; char respbuff_r_[PADR_(unsigned char *)];
	char resplen_l_[PADL_(int)]; int resplen; char resplen_r_[PADR_(int)];
	char datalen_l_[PADL_(int)]; int datalen; char datalen_r_[PADR_(int)];
};
struct ATPgetreq_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(unsigned char *)]; unsigned char * buf; char buf_r_[PADR_(unsigned char *)];
	char buflen_l_[PADL_(int)]; int buflen; char buflen_r_[PADR_(int)];
};
struct ATPgetrsp_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char bdsp_l_[PADL_(unsigned char *)]; unsigned char * bdsp; char bdsp_r_[PADR_(unsigned char *)];
};
struct getattrlist_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char alist_l_[PADL_(user_addr_t)]; user_addr_t alist; char alist_r_[PADR_(user_addr_t)];
	char attributeBuffer_l_[PADL_(user_addr_t)]; user_addr_t attributeBuffer; char attributeBuffer_r_[PADR_(user_addr_t)];
	char bufferSize_l_[PADL_(user_size_t)]; user_size_t bufferSize; char bufferSize_r_[PADR_(user_size_t)];
	char options_l_[PADL_(user_ulong_t)]; user_ulong_t options; char options_r_[PADR_(user_ulong_t)];
};
struct setattrlist_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char alist_l_[PADL_(user_addr_t)]; user_addr_t alist; char alist_r_[PADR_(user_addr_t)];
	char attributeBuffer_l_[PADL_(user_addr_t)]; user_addr_t attributeBuffer; char attributeBuffer_r_[PADR_(user_addr_t)];
	char bufferSize_l_[PADL_(user_size_t)]; user_size_t bufferSize; char bufferSize_r_[PADR_(user_size_t)];
	char options_l_[PADL_(user_ulong_t)]; user_ulong_t options; char options_r_[PADR_(user_ulong_t)];
};
struct getdirentriesattr_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char alist_l_[PADL_(user_addr_t)]; user_addr_t alist; char alist_r_[PADR_(user_addr_t)];
	char buffer_l_[PADL_(user_addr_t)]; user_addr_t buffer; char buffer_r_[PADR_(user_addr_t)];
	char buffersize_l_[PADL_(user_size_t)]; user_size_t buffersize; char buffersize_r_[PADR_(user_size_t)];
	char count_l_[PADL_(user_addr_t)]; user_addr_t count; char count_r_[PADR_(user_addr_t)];
	char basep_l_[PADL_(user_addr_t)]; user_addr_t basep; char basep_r_[PADR_(user_addr_t)];
	char newstate_l_[PADL_(user_addr_t)]; user_addr_t newstate; char newstate_r_[PADR_(user_addr_t)];
	char options_l_[PADL_(user_ulong_t)]; user_ulong_t options; char options_r_[PADR_(user_ulong_t)];
};
struct exchangedata_args {
	char path1_l_[PADL_(user_addr_t)]; user_addr_t path1; char path1_r_[PADR_(user_addr_t)];
	char path2_l_[PADL_(user_addr_t)]; user_addr_t path2; char path2_r_[PADR_(user_addr_t)];
	char options_l_[PADL_(user_ulong_t)]; user_ulong_t options; char options_r_[PADR_(user_ulong_t)];
};
struct searchfs_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char searchblock_l_[PADL_(user_addr_t)]; user_addr_t searchblock; char searchblock_r_[PADR_(user_addr_t)];
	char nummatches_l_[PADL_(user_addr_t)]; user_addr_t nummatches; char nummatches_r_[PADR_(user_addr_t)];
	char scriptcode_l_[PADL_(uint32_t)]; uint32_t scriptcode; char scriptcode_r_[PADR_(uint32_t)];
	char options_l_[PADL_(uint32_t)]; uint32_t options; char options_r_[PADR_(uint32_t)];
	char state_l_[PADL_(user_addr_t)]; user_addr_t state; char state_r_[PADR_(user_addr_t)];
};
struct delete_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct copyfile_args {
	char from_l_[PADL_(user_addr_t)]; user_addr_t from; char from_r_[PADR_(user_addr_t)];
	char to_l_[PADL_(user_addr_t)]; user_addr_t to; char to_r_[PADR_(user_addr_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct fgetattrlist_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char alist_l_[PADL_(user_addr_t)]; user_addr_t alist; char alist_r_[PADR_(user_addr_t)];
	char attributeBuffer_l_[PADL_(user_addr_t)]; user_addr_t attributeBuffer; char attributeBuffer_r_[PADR_(user_addr_t)];
	char bufferSize_l_[PADL_(user_size_t)]; user_size_t bufferSize; char bufferSize_r_[PADR_(user_size_t)];
	char options_l_[PADL_(user_ulong_t)]; user_ulong_t options; char options_r_[PADR_(user_ulong_t)];
};
struct fsetattrlist_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char alist_l_[PADL_(user_addr_t)]; user_addr_t alist; char alist_r_[PADR_(user_addr_t)];
	char attributeBuffer_l_[PADL_(user_addr_t)]; user_addr_t attributeBuffer; char attributeBuffer_r_[PADR_(user_addr_t)];
	char bufferSize_l_[PADL_(user_size_t)]; user_size_t bufferSize; char bufferSize_r_[PADR_(user_size_t)];
	char options_l_[PADL_(user_ulong_t)]; user_ulong_t options; char options_r_[PADR_(user_ulong_t)];
};
struct poll_args {
	char fds_l_[PADL_(user_addr_t)]; user_addr_t fds; char fds_r_[PADR_(user_addr_t)];
	char nfds_l_[PADL_(u_int)]; u_int nfds; char nfds_r_[PADR_(u_int)];
	char timeout_l_[PADL_(int)]; int timeout; char timeout_r_[PADR_(int)];
};
struct watchevent_args {
	char u_req_l_[PADL_(user_addr_t)]; user_addr_t u_req; char u_req_r_[PADR_(user_addr_t)];
	char u_eventmask_l_[PADL_(int)]; int u_eventmask; char u_eventmask_r_[PADR_(int)];
};
struct waitevent_args {
	char u_req_l_[PADL_(user_addr_t)]; user_addr_t u_req; char u_req_r_[PADR_(user_addr_t)];
	char tv_l_[PADL_(user_addr_t)]; user_addr_t tv; char tv_r_[PADR_(user_addr_t)];
};
struct modwatch_args {
	char u_req_l_[PADL_(user_addr_t)]; user_addr_t u_req; char u_req_r_[PADR_(user_addr_t)];
	char u_eventmask_l_[PADL_(int)]; int u_eventmask; char u_eventmask_r_[PADR_(int)];
};
struct getxattr_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char attrname_l_[PADL_(user_addr_t)]; user_addr_t attrname; char attrname_r_[PADR_(user_addr_t)];
	char value_l_[PADL_(user_addr_t)]; user_addr_t value; char value_r_[PADR_(user_addr_t)];
	char size_l_[PADL_(user_size_t)]; user_size_t size; char size_r_[PADR_(user_size_t)];
	char position_l_[PADL_(uint32_t)]; uint32_t position; char position_r_[PADR_(uint32_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
};
struct fgetxattr_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char attrname_l_[PADL_(user_addr_t)]; user_addr_t attrname; char attrname_r_[PADR_(user_addr_t)];
	char value_l_[PADL_(user_addr_t)]; user_addr_t value; char value_r_[PADR_(user_addr_t)];
	char size_l_[PADL_(user_size_t)]; user_size_t size; char size_r_[PADR_(user_size_t)];
	char position_l_[PADL_(uint32_t)]; uint32_t position; char position_r_[PADR_(uint32_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
};
struct setxattr_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char attrname_l_[PADL_(user_addr_t)]; user_addr_t attrname; char attrname_r_[PADR_(user_addr_t)];
	char value_l_[PADL_(user_addr_t)]; user_addr_t value; char value_r_[PADR_(user_addr_t)];
	char size_l_[PADL_(user_size_t)]; user_size_t size; char size_r_[PADR_(user_size_t)];
	char position_l_[PADL_(uint32_t)]; uint32_t position; char position_r_[PADR_(uint32_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
};
struct fsetxattr_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char attrname_l_[PADL_(user_addr_t)]; user_addr_t attrname; char attrname_r_[PADR_(user_addr_t)];
	char value_l_[PADL_(user_addr_t)]; user_addr_t value; char value_r_[PADR_(user_addr_t)];
	char size_l_[PADL_(user_size_t)]; user_size_t size; char size_r_[PADR_(user_size_t)];
	char position_l_[PADL_(uint32_t)]; uint32_t position; char position_r_[PADR_(uint32_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
};
struct removexattr_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char attrname_l_[PADL_(user_addr_t)]; user_addr_t attrname; char attrname_r_[PADR_(user_addr_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
};
struct fremovexattr_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char attrname_l_[PADL_(user_addr_t)]; user_addr_t attrname; char attrname_r_[PADR_(user_addr_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
};
struct listxattr_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char namebuf_l_[PADL_(user_addr_t)]; user_addr_t namebuf; char namebuf_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(user_size_t)]; user_size_t bufsize; char bufsize_r_[PADR_(user_size_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
};
struct flistxattr_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char namebuf_l_[PADL_(user_addr_t)]; user_addr_t namebuf; char namebuf_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(user_size_t)]; user_size_t bufsize; char bufsize_r_[PADR_(user_size_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
};
struct fsctl_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char cmd_l_[PADL_(user_ulong_t)]; user_ulong_t cmd; char cmd_r_[PADR_(user_ulong_t)];
	char data_l_[PADL_(user_addr_t)]; user_addr_t data; char data_r_[PADR_(user_addr_t)];
	char options_l_[PADL_(u_int)]; u_int options; char options_r_[PADR_(u_int)];
};
struct initgroups_args {
	char gidsetsize_l_[PADL_(u_int)]; u_int gidsetsize; char gidsetsize_r_[PADR_(u_int)];
	char gidset_l_[PADL_(user_addr_t)]; user_addr_t gidset; char gidset_r_[PADR_(user_addr_t)];
	char gmuid_l_[PADL_(int)]; int gmuid; char gmuid_r_[PADR_(int)];
};
struct posix_spawn_args {
	char pid_l_[PADL_(user_addr_t)]; user_addr_t pid; char pid_r_[PADR_(user_addr_t)];
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char adesc_l_[PADL_(user_addr_t)]; user_addr_t adesc; char adesc_r_[PADR_(user_addr_t)];
	char argv_l_[PADL_(user_addr_t)]; user_addr_t argv; char argv_r_[PADR_(user_addr_t)];
	char envp_l_[PADL_(user_addr_t)]; user_addr_t envp; char envp_r_[PADR_(user_addr_t)];
};
struct ffsctl_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char cmd_l_[PADL_(user_ulong_t)]; user_ulong_t cmd; char cmd_r_[PADR_(user_ulong_t)];
	char data_l_[PADL_(user_addr_t)]; user_addr_t data; char data_r_[PADR_(user_addr_t)];
	char options_l_[PADL_(u_int)]; u_int options; char options_r_[PADR_(u_int)];
};
struct nfsclnt_args {
	char flag_l_[PADL_(int)]; int flag; char flag_r_[PADR_(int)];
	char argp_l_[PADL_(user_addr_t)]; user_addr_t argp; char argp_r_[PADR_(user_addr_t)];
};
struct fhopen_args {
	char u_fhp_l_[PADL_(user_addr_t)]; user_addr_t u_fhp; char u_fhp_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct minherit_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char inherit_l_[PADL_(int)]; int inherit; char inherit_r_[PADR_(int)];
};
struct semsys_args {
	char which_l_[PADL_(u_int)]; u_int which; char which_r_[PADR_(u_int)];
	char a2_l_[PADL_(int)]; int a2; char a2_r_[PADR_(int)];
	char a3_l_[PADL_(int)]; int a3; char a3_r_[PADR_(int)];
	char a4_l_[PADL_(int)]; int a4; char a4_r_[PADR_(int)];
	char a5_l_[PADL_(int)]; int a5; char a5_r_[PADR_(int)];
};
struct msgsys_args {
	char which_l_[PADL_(u_int)]; u_int which; char which_r_[PADR_(u_int)];
	char a2_l_[PADL_(int)]; int a2; char a2_r_[PADR_(int)];
	char a3_l_[PADL_(int)]; int a3; char a3_r_[PADR_(int)];
	char a4_l_[PADL_(int)]; int a4; char a4_r_[PADR_(int)];
	char a5_l_[PADL_(int)]; int a5; char a5_r_[PADR_(int)];
};
struct shmsys_args {
	char which_l_[PADL_(u_int)]; u_int which; char which_r_[PADR_(u_int)];
	char a2_l_[PADL_(int)]; int a2; char a2_r_[PADR_(int)];
	char a3_l_[PADL_(int)]; int a3; char a3_r_[PADR_(int)];
	char a4_l_[PADL_(int)]; int a4; char a4_r_[PADR_(int)];
};
struct semctl_args {
	char semid_l_[PADL_(int)]; int semid; char semid_r_[PADR_(int)];
	char semnum_l_[PADL_(int)]; int semnum; char semnum_r_[PADR_(int)];
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char arg_l_[PADL_(user_addr_t)]; user_addr_t arg; char arg_r_[PADR_(user_addr_t)];
};
struct semget_args {
	char key_l_[PADL_(key_t)]; key_t key; char key_r_[PADR_(key_t)];
	char nsems_l_[PADL_(int)]; int nsems; char nsems_r_[PADR_(int)];
	char semflg_l_[PADL_(int)]; int semflg; char semflg_r_[PADR_(int)];
};
struct semop_args {
	char semid_l_[PADL_(int)]; int semid; char semid_r_[PADR_(int)];
	char sops_l_[PADL_(user_addr_t)]; user_addr_t sops; char sops_r_[PADR_(user_addr_t)];
	char nsops_l_[PADL_(int)]; int nsops; char nsops_r_[PADR_(int)];
};
struct msgctl_args {
	char msqid_l_[PADL_(int)]; int msqid; char msqid_r_[PADR_(int)];
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
};
struct msgget_args {
	char key_l_[PADL_(key_t)]; key_t key; char key_r_[PADR_(key_t)];
	char msgflg_l_[PADL_(int)]; int msgflg; char msgflg_r_[PADR_(int)];
};
struct msgsnd_args {
	char msqid_l_[PADL_(int)]; int msqid; char msqid_r_[PADR_(int)];
	char msgp_l_[PADL_(user_addr_t)]; user_addr_t msgp; char msgp_r_[PADR_(user_addr_t)];
	char msgsz_l_[PADL_(user_size_t)]; user_size_t msgsz; char msgsz_r_[PADR_(user_size_t)];
	char msgflg_l_[PADL_(int)]; int msgflg; char msgflg_r_[PADR_(int)];
};
struct msgrcv_args {
	char msqid_l_[PADL_(int)]; int msqid; char msqid_r_[PADR_(int)];
	char msgp_l_[PADL_(user_addr_t)]; user_addr_t msgp; char msgp_r_[PADR_(user_addr_t)];
	char msgsz_l_[PADL_(user_size_t)]; user_size_t msgsz; char msgsz_r_[PADR_(user_size_t)];
	char msgtyp_l_[PADL_(user_long_t)]; user_long_t msgtyp; char msgtyp_r_[PADR_(user_long_t)];
	char msgflg_l_[PADL_(int)]; int msgflg; char msgflg_r_[PADR_(int)];
};
struct shmat_args {
	char shmid_l_[PADL_(int)]; int shmid; char shmid_r_[PADR_(int)];
	char shmaddr_l_[PADL_(user_addr_t)]; user_addr_t shmaddr; char shmaddr_r_[PADR_(user_addr_t)];
	char shmflg_l_[PADL_(int)]; int shmflg; char shmflg_r_[PADR_(int)];
};
struct shmctl_args {
	char shmid_l_[PADL_(int)]; int shmid; char shmid_r_[PADR_(int)];
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
};
struct shmdt_args {
	char shmaddr_l_[PADL_(user_addr_t)]; user_addr_t shmaddr; char shmaddr_r_[PADR_(user_addr_t)];
};
struct shmget_args {
	char key_l_[PADL_(key_t)]; key_t key; char key_r_[PADR_(key_t)];
	char size_l_[PADL_(user_size_t)]; user_size_t size; char size_r_[PADR_(user_size_t)];
	char shmflg_l_[PADL_(int)]; int shmflg; char shmflg_r_[PADR_(int)];
};
struct shm_open_args {
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
	char oflag_l_[PADL_(int)]; int oflag; char oflag_r_[PADR_(int)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
};
struct shm_unlink_args {
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
};
struct sem_open_args {
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
	char oflag_l_[PADL_(int)]; int oflag; char oflag_r_[PADR_(int)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char value_l_[PADL_(int)]; int value; char value_r_[PADR_(int)];
};
struct sem_close_args {
	char sem_l_[PADL_(user_addr_t)]; user_addr_t sem; char sem_r_[PADR_(user_addr_t)];
};
struct sem_unlink_args {
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
};
struct sem_wait_args {
	char sem_l_[PADL_(user_addr_t)]; user_addr_t sem; char sem_r_[PADR_(user_addr_t)];
};
struct sem_trywait_args {
	char sem_l_[PADL_(user_addr_t)]; user_addr_t sem; char sem_r_[PADR_(user_addr_t)];
};
struct sem_post_args {
	char sem_l_[PADL_(user_addr_t)]; user_addr_t sem; char sem_r_[PADR_(user_addr_t)];
};
struct sem_getvalue_args {
	char sem_l_[PADL_(user_addr_t)]; user_addr_t sem; char sem_r_[PADR_(user_addr_t)];
	char sval_l_[PADL_(user_addr_t)]; user_addr_t sval; char sval_r_[PADR_(user_addr_t)];
};
struct sem_init_args {
	char sem_l_[PADL_(user_addr_t)]; user_addr_t sem; char sem_r_[PADR_(user_addr_t)];
	char phsared_l_[PADL_(int)]; int phsared; char phsared_r_[PADR_(int)];
	char value_l_[PADL_(u_int)]; u_int value; char value_r_[PADR_(u_int)];
};
struct sem_destroy_args {
	char sem_l_[PADL_(user_addr_t)]; user_addr_t sem; char sem_r_[PADR_(user_addr_t)];
};
struct open_extended_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char uid_l_[PADL_(uid_t)]; uid_t uid; char uid_r_[PADR_(uid_t)];
	char gid_l_[PADL_(gid_t)]; gid_t gid; char gid_r_[PADR_(gid_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
};
struct umask_extended_args {
	char newmask_l_[PADL_(int)]; int newmask; char newmask_r_[PADR_(int)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
};
struct stat_extended_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
	char xsecurity_size_l_[PADL_(user_addr_t)]; user_addr_t xsecurity_size; char xsecurity_size_r_[PADR_(user_addr_t)];
};
struct lstat_extended_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
	char xsecurity_size_l_[PADL_(user_addr_t)]; user_addr_t xsecurity_size; char xsecurity_size_r_[PADR_(user_addr_t)];
};
struct fstat_extended_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
	char xsecurity_size_l_[PADL_(user_addr_t)]; user_addr_t xsecurity_size; char xsecurity_size_r_[PADR_(user_addr_t)];
};
struct chmod_extended_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char uid_l_[PADL_(uid_t)]; uid_t uid; char uid_r_[PADR_(uid_t)];
	char gid_l_[PADL_(gid_t)]; gid_t gid; char gid_r_[PADR_(gid_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
};
struct fchmod_extended_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char uid_l_[PADL_(uid_t)]; uid_t uid; char uid_r_[PADR_(uid_t)];
	char gid_l_[PADL_(gid_t)]; gid_t gid; char gid_r_[PADR_(gid_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
};
struct access_extended_args {
	char entries_l_[PADL_(user_addr_t)]; user_addr_t entries; char entries_r_[PADR_(user_addr_t)];
	char size_l_[PADL_(user_size_t)]; user_size_t size; char size_r_[PADR_(user_size_t)];
	char results_l_[PADL_(user_addr_t)]; user_addr_t results; char results_r_[PADR_(user_addr_t)];
	char uid_l_[PADL_(uid_t)]; uid_t uid; char uid_r_[PADR_(uid_t)];
};
struct settid_args {
	char uid_l_[PADL_(uid_t)]; uid_t uid; char uid_r_[PADR_(uid_t)];
	char gid_l_[PADL_(gid_t)]; gid_t gid; char gid_r_[PADR_(gid_t)];
};
struct gettid_args {
	char uidp_l_[PADL_(user_addr_t)]; user_addr_t uidp; char uidp_r_[PADR_(user_addr_t)];
	char gidp_l_[PADL_(user_addr_t)]; user_addr_t gidp; char gidp_r_[PADR_(user_addr_t)];
};
struct setsgroups_args {
	char setlen_l_[PADL_(int)]; int setlen; char setlen_r_[PADR_(int)];
	char guidset_l_[PADL_(user_addr_t)]; user_addr_t guidset; char guidset_r_[PADR_(user_addr_t)];
};
struct getsgroups_args {
	char setlen_l_[PADL_(user_addr_t)]; user_addr_t setlen; char setlen_r_[PADR_(user_addr_t)];
	char guidset_l_[PADL_(user_addr_t)]; user_addr_t guidset; char guidset_r_[PADR_(user_addr_t)];
};
struct setwgroups_args {
	char setlen_l_[PADL_(int)]; int setlen; char setlen_r_[PADR_(int)];
	char guidset_l_[PADL_(user_addr_t)]; user_addr_t guidset; char guidset_r_[PADR_(user_addr_t)];
};
struct getwgroups_args {
	char setlen_l_[PADL_(user_addr_t)]; user_addr_t setlen; char setlen_r_[PADR_(user_addr_t)];
	char guidset_l_[PADL_(user_addr_t)]; user_addr_t guidset; char guidset_r_[PADR_(user_addr_t)];
};
struct mkfifo_extended_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char uid_l_[PADL_(uid_t)]; uid_t uid; char uid_r_[PADR_(uid_t)];
	char gid_l_[PADL_(gid_t)]; gid_t gid; char gid_r_[PADR_(gid_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
};
struct mkdir_extended_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char uid_l_[PADL_(uid_t)]; uid_t uid; char uid_r_[PADR_(uid_t)];
	char gid_l_[PADL_(gid_t)]; gid_t gid; char gid_r_[PADR_(gid_t)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
};
struct identitysvc_args {
	char opcode_l_[PADL_(int)]; int opcode; char opcode_r_[PADR_(int)];
	char message_l_[PADL_(user_addr_t)]; user_addr_t message; char message_r_[PADR_(user_addr_t)];
};
struct shared_region_check_np_args {
	char start_address_l_[PADL_(user_addr_t)]; user_addr_t start_address; char start_address_r_[PADR_(user_addr_t)];
};
struct vm_pressure_monitor_args {
	char wait_for_pressure_l_[PADL_(int)]; int wait_for_pressure; char wait_for_pressure_r_[PADR_(int)];
	char nsecs_monitored_l_[PADL_(int)]; int nsecs_monitored; char nsecs_monitored_r_[PADR_(int)];
	char pages_reclaimed_l_[PADL_(user_addr_t)]; user_addr_t pages_reclaimed; char pages_reclaimed_r_[PADR_(user_addr_t)];
};
struct psynch_rw_longrdlock_args {
	char rwlock_l_[PADL_(user_addr_t)]; user_addr_t rwlock; char rwlock_r_[PADR_(user_addr_t)];
	char lgenval_l_[PADL_(uint32_t)]; uint32_t lgenval; char lgenval_r_[PADR_(uint32_t)];
	char ugenval_l_[PADL_(uint32_t)]; uint32_t ugenval; char ugenval_r_[PADR_(uint32_t)];
	char rw_wc_l_[PADL_(uint32_t)]; uint32_t rw_wc; char rw_wc_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct psynch_rw_yieldwrlock_args {
	char rwlock_l_[PADL_(user_addr_t)]; user_addr_t rwlock; char rwlock_r_[PADR_(user_addr_t)];
	char lgenval_l_[PADL_(uint32_t)]; uint32_t lgenval; char lgenval_r_[PADR_(uint32_t)];
	char ugenval_l_[PADL_(uint32_t)]; uint32_t ugenval; char ugenval_r_[PADR_(uint32_t)];
	char rw_wc_l_[PADL_(uint32_t)]; uint32_t rw_wc; char rw_wc_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct psynch_rw_downgrade_args {
	char rwlock_l_[PADL_(user_addr_t)]; user_addr_t rwlock; char rwlock_r_[PADR_(user_addr_t)];
	char lgenval_l_[PADL_(uint32_t)]; uint32_t lgenval; char lgenval_r_[PADR_(uint32_t)];
	char ugenval_l_[PADL_(uint32_t)]; uint32_t ugenval; char ugenval_r_[PADR_(uint32_t)];
	char rw_wc_l_[PADL_(uint32_t)]; uint32_t rw_wc; char rw_wc_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct psynch_rw_upgrade_args {
	char rwlock_l_[PADL_(user_addr_t)]; user_addr_t rwlock; char rwlock_r_[PADR_(user_addr_t)];
	char lgenval_l_[PADL_(uint32_t)]; uint32_t lgenval; char lgenval_r_[PADR_(uint32_t)];
	char ugenval_l_[PADL_(uint32_t)]; uint32_t ugenval; char ugenval_r_[PADR_(uint32_t)];
	char rw_wc_l_[PADL_(uint32_t)]; uint32_t rw_wc; char rw_wc_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct psynch_mutexwait_args {
	char mutex_l_[PADL_(user_addr_t)]; user_addr_t mutex; char mutex_r_[PADR_(user_addr_t)];
	char mgen_l_[PADL_(uint32_t)]; uint32_t mgen; char mgen_r_[PADR_(uint32_t)];
	char ugen_l_[PADL_(uint32_t)]; uint32_t ugen; char ugen_r_[PADR_(uint32_t)];
	char tid_l_[PADL_(uint64_t)]; uint64_t tid; char tid_r_[PADR_(uint64_t)];
	char flags_l_[PADL_(uint32_t)]; uint32_t flags; char flags_r_[PADR_(uint32_t)];
};
struct psynch_mutexdrop_args {
	char mutex_l_[PADL_(user_addr_t)]; user_addr_t mutex; char mutex_r_[PADR_(user_addr_t)];
	char mgen_l_[PADL_(uint32_t)]; uint32_t mgen; char mgen_r_[PADR_(uint32_t)];
	char ugen_l_[PADL_(uint32_t)]; uint32_t ugen; char ugen_r_[PADR_(uint32_t)];
	char tid_l_[PADL_(uint64_t)]; uint64_t tid; char tid_r_[PADR_(uint64_t)];
	char flags_l_[PADL_(uint32_t)]; uint32_t flags; char flags_r_[PADR_(uint32_t)];
};
struct psynch_cvbroad_args {
	char cv_l_[PADL_(user_addr_t)]; user_addr_t cv; char cv_r_[PADR_(user_addr_t)];
	char cvlsgen_l_[PADL_(uint64_t)]; uint64_t cvlsgen; char cvlsgen_r_[PADR_(uint64_t)];
	char cvudgen_l_[PADL_(uint64_t)]; uint64_t cvudgen; char cvudgen_r_[PADR_(uint64_t)];
	char flags_l_[PADL_(uint32_t)]; uint32_t flags; char flags_r_[PADR_(uint32_t)];
	char mutex_l_[PADL_(user_addr_t)]; user_addr_t mutex; char mutex_r_[PADR_(user_addr_t)];
	char mugen_l_[PADL_(uint64_t)]; uint64_t mugen; char mugen_r_[PADR_(uint64_t)];
	char tid_l_[PADL_(uint64_t)]; uint64_t tid; char tid_r_[PADR_(uint64_t)];
};
struct psynch_cvsignal_args {
	char cv_l_[PADL_(user_addr_t)]; user_addr_t cv; char cv_r_[PADR_(user_addr_t)];
	char cvlsgen_l_[PADL_(uint64_t)]; uint64_t cvlsgen; char cvlsgen_r_[PADR_(uint64_t)];
	char cvugen_l_[PADL_(uint32_t)]; uint32_t cvugen; char cvugen_r_[PADR_(uint32_t)];
	char thread_port_l_[PADL_(int)]; int thread_port; char thread_port_r_[PADR_(int)];
	char mutex_l_[PADL_(user_addr_t)]; user_addr_t mutex; char mutex_r_[PADR_(user_addr_t)];
	char mugen_l_[PADL_(uint64_t)]; uint64_t mugen; char mugen_r_[PADR_(uint64_t)];
	char tid_l_[PADL_(uint64_t)]; uint64_t tid; char tid_r_[PADR_(uint64_t)];
	char flags_l_[PADL_(uint32_t)]; uint32_t flags; char flags_r_[PADR_(uint32_t)];
};
struct psynch_cvwait_args {
	char cv_l_[PADL_(user_addr_t)]; user_addr_t cv; char cv_r_[PADR_(user_addr_t)];
	char cvlsgen_l_[PADL_(uint64_t)]; uint64_t cvlsgen; char cvlsgen_r_[PADR_(uint64_t)];
	char cvugen_l_[PADL_(uint32_t)]; uint32_t cvugen; char cvugen_r_[PADR_(uint32_t)];
	char mutex_l_[PADL_(user_addr_t)]; user_addr_t mutex; char mutex_r_[PADR_(user_addr_t)];
	char mugen_l_[PADL_(uint64_t)]; uint64_t mugen; char mugen_r_[PADR_(uint64_t)];
	char flags_l_[PADL_(uint32_t)]; uint32_t flags; char flags_r_[PADR_(uint32_t)];
	char sec_l_[PADL_(int64_t)]; int64_t sec; char sec_r_[PADR_(int64_t)];
	char nsec_l_[PADL_(uint32_t)]; uint32_t nsec; char nsec_r_[PADR_(uint32_t)];
};
struct psynch_rw_rdlock_args {
	char rwlock_l_[PADL_(user_addr_t)]; user_addr_t rwlock; char rwlock_r_[PADR_(user_addr_t)];
	char lgenval_l_[PADL_(uint32_t)]; uint32_t lgenval; char lgenval_r_[PADR_(uint32_t)];
	char ugenval_l_[PADL_(uint32_t)]; uint32_t ugenval; char ugenval_r_[PADR_(uint32_t)];
	char rw_wc_l_[PADL_(uint32_t)]; uint32_t rw_wc; char rw_wc_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct psynch_rw_wrlock_args {
	char rwlock_l_[PADL_(user_addr_t)]; user_addr_t rwlock; char rwlock_r_[PADR_(user_addr_t)];
	char lgenval_l_[PADL_(uint32_t)]; uint32_t lgenval; char lgenval_r_[PADR_(uint32_t)];
	char ugenval_l_[PADL_(uint32_t)]; uint32_t ugenval; char ugenval_r_[PADR_(uint32_t)];
	char rw_wc_l_[PADL_(uint32_t)]; uint32_t rw_wc; char rw_wc_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct psynch_rw_unlock_args {
	char rwlock_l_[PADL_(user_addr_t)]; user_addr_t rwlock; char rwlock_r_[PADR_(user_addr_t)];
	char lgenval_l_[PADL_(uint32_t)]; uint32_t lgenval; char lgenval_r_[PADR_(uint32_t)];
	char ugenval_l_[PADL_(uint32_t)]; uint32_t ugenval; char ugenval_r_[PADR_(uint32_t)];
	char rw_wc_l_[PADL_(uint32_t)]; uint32_t rw_wc; char rw_wc_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct psynch_rw_unlock2_args {
	char rwlock_l_[PADL_(user_addr_t)]; user_addr_t rwlock; char rwlock_r_[PADR_(user_addr_t)];
	char lgenval_l_[PADL_(uint32_t)]; uint32_t lgenval; char lgenval_r_[PADR_(uint32_t)];
	char ugenval_l_[PADL_(uint32_t)]; uint32_t ugenval; char ugenval_r_[PADR_(uint32_t)];
	char rw_wc_l_[PADL_(uint32_t)]; uint32_t rw_wc; char rw_wc_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct getsid_args {
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
};
struct settid_with_pid_args {
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
	char assume_l_[PADL_(int)]; int assume; char assume_r_[PADR_(int)];
};
struct psynch_cvclrprepost_args {
	char cv_l_[PADL_(user_addr_t)]; user_addr_t cv; char cv_r_[PADR_(user_addr_t)];
	char cvgen_l_[PADL_(uint32_t)]; uint32_t cvgen; char cvgen_r_[PADR_(uint32_t)];
	char cvugen_l_[PADL_(uint32_t)]; uint32_t cvugen; char cvugen_r_[PADR_(uint32_t)];
	char cvsgen_l_[PADL_(uint32_t)]; uint32_t cvsgen; char cvsgen_r_[PADR_(uint32_t)];
	char prepocnt_l_[PADL_(uint32_t)]; uint32_t prepocnt; char prepocnt_r_[PADR_(uint32_t)];
	char preposeq_l_[PADL_(uint32_t)]; uint32_t preposeq; char preposeq_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(uint32_t)]; uint32_t flags; char flags_r_[PADR_(uint32_t)];
};
struct aio_fsync_args {
	char op_l_[PADL_(int)]; int op; char op_r_[PADR_(int)];
	char aiocbp_l_[PADL_(user_addr_t)]; user_addr_t aiocbp; char aiocbp_r_[PADR_(user_addr_t)];
};
struct aio_return_args {
	char aiocbp_l_[PADL_(user_addr_t)]; user_addr_t aiocbp; char aiocbp_r_[PADR_(user_addr_t)];
};
struct aio_suspend_args {
	char aiocblist_l_[PADL_(user_addr_t)]; user_addr_t aiocblist; char aiocblist_r_[PADR_(user_addr_t)];
	char nent_l_[PADL_(int)]; int nent; char nent_r_[PADR_(int)];
	char timeoutp_l_[PADL_(user_addr_t)]; user_addr_t timeoutp; char timeoutp_r_[PADR_(user_addr_t)];
};
struct aio_cancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char aiocbp_l_[PADL_(user_addr_t)]; user_addr_t aiocbp; char aiocbp_r_[PADR_(user_addr_t)];
};
struct aio_error_args {
	char aiocbp_l_[PADL_(user_addr_t)]; user_addr_t aiocbp; char aiocbp_r_[PADR_(user_addr_t)];
};
struct aio_read_args {
	char aiocbp_l_[PADL_(user_addr_t)]; user_addr_t aiocbp; char aiocbp_r_[PADR_(user_addr_t)];
};
struct aio_write_args {
	char aiocbp_l_[PADL_(user_addr_t)]; user_addr_t aiocbp; char aiocbp_r_[PADR_(user_addr_t)];
};
struct lio_listio_args {
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
	char aiocblist_l_[PADL_(user_addr_t)]; user_addr_t aiocblist; char aiocblist_r_[PADR_(user_addr_t)];
	char nent_l_[PADL_(int)]; int nent; char nent_r_[PADR_(int)];
	char sigp_l_[PADL_(user_addr_t)]; user_addr_t sigp; char sigp_r_[PADR_(user_addr_t)];
};
struct iopolicysys_args {
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char arg_l_[PADL_(user_addr_t)]; user_addr_t arg; char arg_r_[PADR_(user_addr_t)];
};
struct process_policy_args {
	char scope_l_[PADL_(int)]; int scope; char scope_r_[PADR_(int)];
	char action_l_[PADL_(int)]; int action; char action_r_[PADR_(int)];
	char policy_l_[PADL_(int)]; int policy; char policy_r_[PADR_(int)];
	char policy_subtype_l_[PADL_(int)]; int policy_subtype; char policy_subtype_r_[PADR_(int)];
	char attrp_l_[PADL_(user_addr_t)]; user_addr_t attrp; char attrp_r_[PADR_(user_addr_t)];
	char target_pid_l_[PADL_(pid_t)]; pid_t target_pid; char target_pid_r_[PADR_(pid_t)];
	char target_threadid_l_[PADL_(uint64_t)]; uint64_t target_threadid; char target_threadid_r_[PADR_(uint64_t)];
};
struct mlockall_args {
	char how_l_[PADL_(int)]; int how; char how_r_[PADR_(int)];
};
struct munlockall_args {
	char how_l_[PADL_(int)]; int how; char how_r_[PADR_(int)];
};
struct issetugid_args {
	int32_t dummy;
};
struct __pthread_kill_args {
	char thread_port_l_[PADL_(int)]; int thread_port; char thread_port_r_[PADR_(int)];
	char sig_l_[PADL_(int)]; int sig; char sig_r_[PADR_(int)];
};
struct __pthread_sigmask_args {
	char how_l_[PADL_(int)]; int how; char how_r_[PADR_(int)];
	char set_l_[PADL_(user_addr_t)]; user_addr_t set; char set_r_[PADR_(user_addr_t)];
	char oset_l_[PADL_(user_addr_t)]; user_addr_t oset; char oset_r_[PADR_(user_addr_t)];
};
struct __sigwait_args {
	char set_l_[PADL_(user_addr_t)]; user_addr_t set; char set_r_[PADR_(user_addr_t)];
	char sig_l_[PADL_(user_addr_t)]; user_addr_t sig; char sig_r_[PADR_(user_addr_t)];
};
struct __disable_threadsignal_args {
	char value_l_[PADL_(int)]; int value; char value_r_[PADR_(int)];
};
struct __pthread_markcancel_args {
	char thread_port_l_[PADL_(int)]; int thread_port; char thread_port_r_[PADR_(int)];
};
struct __pthread_canceled_args {
	char action_l_[PADL_(int)]; int action; char action_r_[PADR_(int)];
};
struct __semwait_signal_args {
	char cond_sem_l_[PADL_(int)]; int cond_sem; char cond_sem_r_[PADR_(int)];
	char mutex_sem_l_[PADL_(int)]; int mutex_sem; char mutex_sem_r_[PADR_(int)];
	char timeout_l_[PADL_(int)]; int timeout; char timeout_r_[PADR_(int)];
	char relative_l_[PADL_(int)]; int relative; char relative_r_[PADR_(int)];
	char tv_sec_l_[PADL_(int64_t)]; int64_t tv_sec; char tv_sec_r_[PADR_(int64_t)];
	char tv_nsec_l_[PADL_(int32_t)]; int32_t tv_nsec; char tv_nsec_r_[PADR_(int32_t)];
};
struct proc_info_args {
	char callnum_l_[PADL_(int32_t)]; int32_t callnum; char callnum_r_[PADR_(int32_t)];
	char pid_l_[PADL_(int32_t)]; int32_t pid; char pid_r_[PADR_(int32_t)];
	char flavor_l_[PADL_(uint32_t)]; uint32_t flavor; char flavor_r_[PADR_(uint32_t)];
	char arg_l_[PADL_(uint64_t)]; uint64_t arg; char arg_r_[PADR_(uint64_t)];
	char buffer_l_[PADL_(user_addr_t)]; user_addr_t buffer; char buffer_r_[PADR_(user_addr_t)];
	char buffersize_l_[PADL_(int32_t)]; int32_t buffersize; char buffersize_r_[PADR_(int32_t)];
};
struct sendfile_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char offset_l_[PADL_(off_t)]; off_t offset; char offset_r_[PADR_(off_t)];
	char nbytes_l_[PADL_(user_addr_t)]; user_addr_t nbytes; char nbytes_r_[PADR_(user_addr_t)];
	char hdtr_l_[PADL_(user_addr_t)]; user_addr_t hdtr; char hdtr_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct stat64_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
};
struct fstat64_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
};
struct lstat64_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
};
struct stat64_extended_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
	char xsecurity_size_l_[PADL_(user_addr_t)]; user_addr_t xsecurity_size; char xsecurity_size_r_[PADR_(user_addr_t)];
};
struct lstat64_extended_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
	char xsecurity_size_l_[PADL_(user_addr_t)]; user_addr_t xsecurity_size; char xsecurity_size_r_[PADR_(user_addr_t)];
};
struct fstat64_extended_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char ub_l_[PADL_(user_addr_t)]; user_addr_t ub; char ub_r_[PADR_(user_addr_t)];
	char xsecurity_l_[PADL_(user_addr_t)]; user_addr_t xsecurity; char xsecurity_r_[PADR_(user_addr_t)];
	char xsecurity_size_l_[PADL_(user_addr_t)]; user_addr_t xsecurity_size; char xsecurity_size_r_[PADR_(user_addr_t)];
};
struct getdirentries64_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(user_size_t)]; user_size_t bufsize; char bufsize_r_[PADR_(user_size_t)];
	char position_l_[PADL_(user_addr_t)]; user_addr_t position; char position_r_[PADR_(user_addr_t)];
};
struct statfs64_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
};
struct fstatfs64_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
};
struct getfsstat64_args {
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(int)]; int bufsize; char bufsize_r_[PADR_(int)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct __pthread_chdir_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct __pthread_fchdir_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
};
struct audit_args {
	char record_l_[PADL_(user_addr_t)]; user_addr_t record; char record_r_[PADR_(user_addr_t)];
	char length_l_[PADL_(int)]; int length; char length_r_[PADR_(int)];
};
struct auditon_args {
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char data_l_[PADL_(user_addr_t)]; user_addr_t data; char data_r_[PADR_(user_addr_t)];
	char length_l_[PADL_(int)]; int length; char length_r_[PADR_(int)];
};
struct getauid_args {
	char auid_l_[PADL_(user_addr_t)]; user_addr_t auid; char auid_r_[PADR_(user_addr_t)];
};
struct setauid_args {
	char auid_l_[PADL_(user_addr_t)]; user_addr_t auid; char auid_r_[PADR_(user_addr_t)];
};
struct getaudit_args {
	char auditinfo_l_[PADL_(user_addr_t)]; user_addr_t auditinfo; char auditinfo_r_[PADR_(user_addr_t)];
};
struct setaudit_args {
	char auditinfo_l_[PADL_(user_addr_t)]; user_addr_t auditinfo; char auditinfo_r_[PADR_(user_addr_t)];
};
struct getaudit_addr_args {
	char auditinfo_addr_l_[PADL_(user_addr_t)]; user_addr_t auditinfo_addr; char auditinfo_addr_r_[PADR_(user_addr_t)];
	char length_l_[PADL_(int)]; int length; char length_r_[PADR_(int)];
};
struct setaudit_addr_args {
	char auditinfo_addr_l_[PADL_(user_addr_t)]; user_addr_t auditinfo_addr; char auditinfo_addr_r_[PADR_(user_addr_t)];
	char length_l_[PADL_(int)]; int length; char length_r_[PADR_(int)];
};
struct auditctl_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
};
struct bsdthread_create_args {
	char func_l_[PADL_(user_addr_t)]; user_addr_t func; char func_r_[PADR_(user_addr_t)];
	char func_arg_l_[PADL_(user_addr_t)]; user_addr_t func_arg; char func_arg_r_[PADR_(user_addr_t)];
	char stack_l_[PADL_(user_addr_t)]; user_addr_t stack; char stack_r_[PADR_(user_addr_t)];
	char pthread_l_[PADL_(user_addr_t)]; user_addr_t pthread; char pthread_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(uint32_t)]; uint32_t flags; char flags_r_[PADR_(uint32_t)];
};
struct bsdthread_terminate_args {
	char stackaddr_l_[PADL_(user_addr_t)]; user_addr_t stackaddr; char stackaddr_r_[PADR_(user_addr_t)];
	char freesize_l_[PADL_(user_size_t)]; user_size_t freesize; char freesize_r_[PADR_(user_size_t)];
	char port_l_[PADL_(uint32_t)]; uint32_t port; char port_r_[PADR_(uint32_t)];
	char sem_l_[PADL_(uint32_t)]; uint32_t sem; char sem_r_[PADR_(uint32_t)];
};
struct kqueue_args {
	int32_t dummy;
};
struct kevent_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char changelist_l_[PADL_(user_addr_t)]; user_addr_t changelist; char changelist_r_[PADR_(user_addr_t)];
	char nchanges_l_[PADL_(int)]; int nchanges; char nchanges_r_[PADR_(int)];
	char eventlist_l_[PADL_(user_addr_t)]; user_addr_t eventlist; char eventlist_r_[PADR_(user_addr_t)];
	char nevents_l_[PADL_(int)]; int nevents; char nevents_r_[PADR_(int)];
	char timeout_l_[PADL_(user_addr_t)]; user_addr_t timeout; char timeout_r_[PADR_(user_addr_t)];
};
struct lchown_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char owner_l_[PADL_(uid_t)]; uid_t owner; char owner_r_[PADR_(uid_t)];
	char group_l_[PADL_(gid_t)]; gid_t group; char group_r_[PADR_(gid_t)];
};
struct stack_snapshot_args {
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
	char tracebuf_l_[PADL_(user_addr_t)]; user_addr_t tracebuf; char tracebuf_r_[PADR_(user_addr_t)];
	char tracebuf_size_l_[PADL_(uint32_t)]; uint32_t tracebuf_size; char tracebuf_size_r_[PADR_(uint32_t)];
	char flags_l_[PADL_(uint32_t)]; uint32_t flags; char flags_r_[PADR_(uint32_t)];
	char dispatch_offset_l_[PADL_(uint32_t)]; uint32_t dispatch_offset; char dispatch_offset_r_[PADR_(uint32_t)];
};
struct bsdthread_register_args {
	char threadstart_l_[PADL_(user_addr_t)]; user_addr_t threadstart; char threadstart_r_[PADR_(user_addr_t)];
	char wqthread_l_[PADL_(user_addr_t)]; user_addr_t wqthread; char wqthread_r_[PADR_(user_addr_t)];
	char pthsize_l_[PADL_(int)]; int pthsize; char pthsize_r_[PADR_(int)];
	char dummy_value_l_[PADL_(user_addr_t)]; user_addr_t dummy_value; char dummy_value_r_[PADR_(user_addr_t)];
	char targetconc_ptr_l_[PADL_(user_addr_t)]; user_addr_t targetconc_ptr; char targetconc_ptr_r_[PADR_(user_addr_t)];
	char dispatchqueue_offset_l_[PADL_(uint64_t)]; uint64_t dispatchqueue_offset; char dispatchqueue_offset_r_[PADR_(uint64_t)];
};
struct workq_open_args {
	int32_t dummy;
};
struct workq_kernreturn_args {
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
	char item_l_[PADL_(user_addr_t)]; user_addr_t item; char item_r_[PADR_(user_addr_t)];
	char affinity_l_[PADL_(int)]; int affinity; char affinity_r_[PADR_(int)];
	char prio_l_[PADL_(int)]; int prio; char prio_r_[PADR_(int)];
};
struct kevent64_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char changelist_l_[PADL_(user_addr_t)]; user_addr_t changelist; char changelist_r_[PADR_(user_addr_t)];
	char nchanges_l_[PADL_(int)]; int nchanges; char nchanges_r_[PADR_(int)];
	char eventlist_l_[PADL_(user_addr_t)]; user_addr_t eventlist; char eventlist_r_[PADR_(user_addr_t)];
	char nevents_l_[PADL_(int)]; int nevents; char nevents_r_[PADR_(int)];
	char flags_l_[PADL_(unsigned int)]; unsigned int flags; char flags_r_[PADR_(unsigned int)];
	char timeout_l_[PADL_(user_addr_t)]; user_addr_t timeout; char timeout_r_[PADR_(user_addr_t)];
};
struct __old_semwait_signal_args {
	char cond_sem_l_[PADL_(int)]; int cond_sem; char cond_sem_r_[PADR_(int)];
	char mutex_sem_l_[PADL_(int)]; int mutex_sem; char mutex_sem_r_[PADR_(int)];
	char timeout_l_[PADL_(int)]; int timeout; char timeout_r_[PADR_(int)];
	char relative_l_[PADL_(int)]; int relative; char relative_r_[PADR_(int)];
	char ts_l_[PADL_(user_addr_t)]; user_addr_t ts; char ts_r_[PADR_(user_addr_t)];
};
struct __old_semwait_signal_nocancel_args {
	char cond_sem_l_[PADL_(int)]; int cond_sem; char cond_sem_r_[PADR_(int)];
	char mutex_sem_l_[PADL_(int)]; int mutex_sem; char mutex_sem_r_[PADR_(int)];
	char timeout_l_[PADL_(int)]; int timeout; char timeout_r_[PADR_(int)];
	char relative_l_[PADL_(int)]; int relative; char relative_r_[PADR_(int)];
	char ts_l_[PADL_(user_addr_t)]; user_addr_t ts; char ts_r_[PADR_(user_addr_t)];
};
struct thread_selfid_args {
	int32_t dummy;
};
struct __mac_execve_args {
	char fname_l_[PADL_(user_addr_t)]; user_addr_t fname; char fname_r_[PADR_(user_addr_t)];
	char argp_l_[PADL_(user_addr_t)]; user_addr_t argp; char argp_r_[PADR_(user_addr_t)];
	char envp_l_[PADL_(user_addr_t)]; user_addr_t envp; char envp_r_[PADR_(user_addr_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_syscall_args {
	char policy_l_[PADL_(user_addr_t)]; user_addr_t policy; char policy_r_[PADR_(user_addr_t)];
	char call_l_[PADL_(int)]; int call; char call_r_[PADR_(int)];
	char arg_l_[PADL_(user_addr_t)]; user_addr_t arg; char arg_r_[PADR_(user_addr_t)];
};
struct __mac_get_file_args {
	char path_p_l_[PADL_(user_addr_t)]; user_addr_t path_p; char path_p_r_[PADR_(user_addr_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_set_file_args {
	char path_p_l_[PADL_(user_addr_t)]; user_addr_t path_p; char path_p_r_[PADR_(user_addr_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_get_link_args {
	char path_p_l_[PADL_(user_addr_t)]; user_addr_t path_p; char path_p_r_[PADR_(user_addr_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_set_link_args {
	char path_p_l_[PADL_(user_addr_t)]; user_addr_t path_p; char path_p_r_[PADR_(user_addr_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_get_proc_args {
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_set_proc_args {
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_get_fd_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_set_fd_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_get_pid_args {
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_get_lcid_args {
	char lcid_l_[PADL_(pid_t)]; pid_t lcid; char lcid_r_[PADR_(pid_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_get_lctx_args {
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_set_lctx_args {
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct setlcid_args {
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
	char lcid_l_[PADL_(pid_t)]; pid_t lcid; char lcid_r_[PADR_(pid_t)];
};
struct getlcid_args {
	char pid_l_[PADL_(pid_t)]; pid_t pid; char pid_r_[PADR_(pid_t)];
};
struct read_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char cbuf_l_[PADL_(user_addr_t)]; user_addr_t cbuf; char cbuf_r_[PADR_(user_addr_t)];
	char nbyte_l_[PADL_(user_size_t)]; user_size_t nbyte; char nbyte_r_[PADR_(user_size_t)];
};
struct write_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char cbuf_l_[PADL_(user_addr_t)]; user_addr_t cbuf; char cbuf_r_[PADR_(user_addr_t)];
	char nbyte_l_[PADL_(user_size_t)]; user_size_t nbyte; char nbyte_r_[PADR_(user_size_t)];
};
struct open_nocancel_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char mode_l_[PADL_(int)]; int mode; char mode_r_[PADR_(int)];
};
struct close_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
};
struct wait4_nocancel_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
	char status_l_[PADL_(user_addr_t)]; user_addr_t status; char status_r_[PADR_(user_addr_t)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
	char rusage_l_[PADL_(user_addr_t)]; user_addr_t rusage; char rusage_r_[PADR_(user_addr_t)];
};
struct recvmsg_nocancel_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char msg_l_[PADL_(user_addr_t)]; user_addr_t msg; char msg_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct sendmsg_nocancel_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char msg_l_[PADL_(user_addr_t)]; user_addr_t msg; char msg_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct recvfrom_nocancel_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char from_l_[PADL_(user_addr_t)]; user_addr_t from; char from_r_[PADR_(user_addr_t)];
	char fromlenaddr_l_[PADL_(user_addr_t)]; user_addr_t fromlenaddr; char fromlenaddr_r_[PADR_(user_addr_t)];
};
struct accept_nocancel_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
	char anamelen_l_[PADL_(user_addr_t)]; user_addr_t anamelen; char anamelen_r_[PADR_(user_addr_t)];
};
struct msync_nocancel_args {
	char addr_l_[PADL_(user_addr_t)]; user_addr_t addr; char addr_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct fcntl_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char arg_l_[PADL_(user_long_t)]; user_long_t arg; char arg_r_[PADR_(user_long_t)];
};
struct select_nocancel_args {
	char nd_l_[PADL_(int)]; int nd; char nd_r_[PADR_(int)];
	char in_l_[PADL_(user_addr_t)]; user_addr_t in; char in_r_[PADR_(user_addr_t)];
	char ou_l_[PADL_(user_addr_t)]; user_addr_t ou; char ou_r_[PADR_(user_addr_t)];
	char ex_l_[PADL_(user_addr_t)]; user_addr_t ex; char ex_r_[PADR_(user_addr_t)];
	char tv_l_[PADL_(user_addr_t)]; user_addr_t tv; char tv_r_[PADR_(user_addr_t)];
};
struct fsync_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
};
struct connect_nocancel_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char name_l_[PADL_(user_addr_t)]; user_addr_t name; char name_r_[PADR_(user_addr_t)];
	char namelen_l_[PADL_(socklen_t)]; socklen_t namelen; char namelen_r_[PADR_(socklen_t)];
};
struct sigsuspend_nocancel_args {
	char mask_l_[PADL_(sigset_t)]; sigset_t mask; char mask_r_[PADR_(sigset_t)];
};
struct readv_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char iovp_l_[PADL_(user_addr_t)]; user_addr_t iovp; char iovp_r_[PADR_(user_addr_t)];
	char iovcnt_l_[PADL_(u_int)]; u_int iovcnt; char iovcnt_r_[PADR_(u_int)];
};
struct writev_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char iovp_l_[PADL_(user_addr_t)]; user_addr_t iovp; char iovp_r_[PADR_(user_addr_t)];
	char iovcnt_l_[PADL_(u_int)]; u_int iovcnt; char iovcnt_r_[PADR_(u_int)];
};
struct sendto_nocancel_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char len_l_[PADL_(user_size_t)]; user_size_t len; char len_r_[PADR_(user_size_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char to_l_[PADL_(user_addr_t)]; user_addr_t to; char to_r_[PADR_(user_addr_t)];
	char tolen_l_[PADL_(socklen_t)]; socklen_t tolen; char tolen_r_[PADR_(socklen_t)];
};
struct pread_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char nbyte_l_[PADL_(user_size_t)]; user_size_t nbyte; char nbyte_r_[PADR_(user_size_t)];
	char offset_l_[PADL_(off_t)]; off_t offset; char offset_r_[PADR_(off_t)];
};
struct pwrite_nocancel_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char nbyte_l_[PADL_(user_size_t)]; user_size_t nbyte; char nbyte_r_[PADR_(user_size_t)];
	char offset_l_[PADL_(off_t)]; off_t offset; char offset_r_[PADR_(off_t)];
};
/*
 struct waitid_nocancel_args {
 char idtype_l_[PADL_(idtype_t)]; idtype_t idtype; char idtype_r_[PADR_(idtype_t)];
 char id_l_[PADL_(id_t)]; id_t id; char id_r_[PADR_(id_t)];
 char infop_l_[PADL_(user_addr_t)]; user_addr_t infop; char infop_r_[PADR_(user_addr_t)];
 char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
 };
 */
struct poll_nocancel_args {
	char fds_l_[PADL_(user_addr_t)]; user_addr_t fds; char fds_r_[PADR_(user_addr_t)];
	char nfds_l_[PADL_(u_int)]; u_int nfds; char nfds_r_[PADR_(u_int)];
	char timeout_l_[PADL_(int)]; int timeout; char timeout_r_[PADR_(int)];
};
struct msgsnd_nocancel_args {
	char msqid_l_[PADL_(int)]; int msqid; char msqid_r_[PADR_(int)];
	char msgp_l_[PADL_(user_addr_t)]; user_addr_t msgp; char msgp_r_[PADR_(user_addr_t)];
	char msgsz_l_[PADL_(user_size_t)]; user_size_t msgsz; char msgsz_r_[PADR_(user_size_t)];
	char msgflg_l_[PADL_(int)]; int msgflg; char msgflg_r_[PADR_(int)];
};
struct msgrcv_nocancel_args {
	char msqid_l_[PADL_(int)]; int msqid; char msqid_r_[PADR_(int)];
	char msgp_l_[PADL_(user_addr_t)]; user_addr_t msgp; char msgp_r_[PADR_(user_addr_t)];
	char msgsz_l_[PADL_(user_size_t)]; user_size_t msgsz; char msgsz_r_[PADR_(user_size_t)];
	char msgtyp_l_[PADL_(user_long_t)]; user_long_t msgtyp; char msgtyp_r_[PADR_(user_long_t)];
	char msgflg_l_[PADL_(int)]; int msgflg; char msgflg_r_[PADR_(int)];
};
struct sem_wait_nocancel_args {
	char sem_l_[PADL_(user_addr_t)]; user_addr_t sem; char sem_r_[PADR_(user_addr_t)];
};
struct aio_suspend_nocancel_args {
	char aiocblist_l_[PADL_(user_addr_t)]; user_addr_t aiocblist; char aiocblist_r_[PADR_(user_addr_t)];
	char nent_l_[PADL_(int)]; int nent; char nent_r_[PADR_(int)];
	char timeoutp_l_[PADL_(user_addr_t)]; user_addr_t timeoutp; char timeoutp_r_[PADR_(user_addr_t)];
};
struct __sigwait_nocancel_args {
	char set_l_[PADL_(user_addr_t)]; user_addr_t set; char set_r_[PADR_(user_addr_t)];
	char sig_l_[PADL_(user_addr_t)]; user_addr_t sig; char sig_r_[PADR_(user_addr_t)];
};
struct __semwait_signal_nocancel_args {
	char cond_sem_l_[PADL_(int)]; int cond_sem; char cond_sem_r_[PADR_(int)];
	char mutex_sem_l_[PADL_(int)]; int mutex_sem; char mutex_sem_r_[PADR_(int)];
	char timeout_l_[PADL_(int)]; int timeout; char timeout_r_[PADR_(int)];
	char relative_l_[PADL_(int)]; int relative; char relative_r_[PADR_(int)];
	char tv_sec_l_[PADL_(int64_t)]; int64_t tv_sec; char tv_sec_r_[PADR_(int64_t)];
	char tv_nsec_l_[PADL_(int32_t)]; int32_t tv_nsec; char tv_nsec_r_[PADR_(int32_t)];
};
struct __mac_mount_args {
	char type_l_[PADL_(user_addr_t)]; user_addr_t type; char type_r_[PADR_(user_addr_t)];
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char data_l_[PADL_(user_addr_t)]; user_addr_t data; char data_r_[PADR_(user_addr_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_get_mount_args {
	char path_l_[PADL_(user_addr_t)]; user_addr_t path; char path_r_[PADR_(user_addr_t)];
	char mac_p_l_[PADL_(user_addr_t)]; user_addr_t mac_p; char mac_p_r_[PADR_(user_addr_t)];
};
struct __mac_getfsstat_args {
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(int)]; int bufsize; char bufsize_r_[PADR_(int)];
	char mac_l_[PADL_(user_addr_t)]; user_addr_t mac; char mac_r_[PADR_(user_addr_t)];
	char macsize_l_[PADL_(int)]; int macsize; char macsize_r_[PADR_(int)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
};
struct fsgetpath_args {
	char buf_l_[PADL_(user_addr_t)]; user_addr_t buf; char buf_r_[PADR_(user_addr_t)];
	char bufsize_l_[PADL_(user_size_t)]; user_size_t bufsize; char bufsize_r_[PADR_(user_size_t)];
	char fsid_l_[PADL_(user_addr_t)]; user_addr_t fsid; char fsid_r_[PADR_(user_addr_t)];
	char objid_l_[PADL_(uint64_t)]; uint64_t objid; char objid_r_[PADR_(uint64_t)];
};
struct audit_session_self_args {
	int32_t dummy;
};
struct audit_session_join_args {
	char port_l_[PADL_(mach_port_name_t)]; mach_port_name_t port; char port_r_[PADR_(mach_port_name_t)];
};
struct fileport_makeport_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char portnamep_l_[PADL_(user_addr_t)]; user_addr_t portnamep; char portnamep_r_[PADR_(user_addr_t)];
};
struct fileport_makefd_args {
	char port_l_[PADL_(mach_port_name_t)]; mach_port_name_t port; char port_r_[PADR_(mach_port_name_t)];
};
/*
 struct audit_session_port_args {
 char asid_l_[PADL_(au_asid_t)]; au_asid_t asid; char asid_r_[PADR_(au_asid_t)];
 char portnamep_l_[PADL_(user_addr_t)]; user_addr_t portnamep; char portnamep_r_[PADR_(user_addr_t)];
 };
 */
struct pid_suspend_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
};
struct pid_resume_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
};
struct pid_hibernate_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
};
struct pid_shutdown_sockets_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
	char level_l_[PADL_(int)]; int level; char level_r_[PADR_(int)];
};
struct shared_region_map_and_slide_np_args {
	char fd_l_[PADL_(int)]; int fd; char fd_r_[PADR_(int)];
	char count_l_[PADL_(uint32_t)]; uint32_t count; char count_r_[PADR_(uint32_t)];
	char mappings_l_[PADL_(user_addr_t)]; user_addr_t mappings; char mappings_r_[PADR_(user_addr_t)];
	char slide_l_[PADL_(uint32_t)]; uint32_t slide; char slide_r_[PADR_(uint32_t)];
	char slide_start_l_[PADL_(user_addr_t)]; user_addr_t slide_start; char slide_start_r_[PADR_(user_addr_t)];
	char slide_size_l_[PADL_(uint32_t)]; uint32_t slide_size; char slide_size_r_[PADR_(uint32_t)];
};
struct kas_info_args {
	char selector_l_[PADL_(int)]; int selector; char selector_r_[PADR_(int)];
	char value_l_[PADL_(user_addr_t)]; user_addr_t value; char value_r_[PADR_(user_addr_t)];
	char size_l_[PADL_(user_addr_t)]; user_addr_t size; char size_r_[PADR_(user_addr_t)];
};

/*
 int nosys(struct proc *, struct nosys_args *, int *);
 void exit(struct proc *, struct exit_args *, int32_t *);
 int fork(struct proc *, struct fork_args *, int *);
 int read(struct proc *, struct read_args *, user_ssize_t *);
 int write(struct proc *, struct write_args *, user_ssize_t *);
 int open(struct proc *, struct open_args *, int *);
 int close(struct proc *, struct close_args *, int *);
 int wait4(struct proc *, struct wait4_args *, int *);
 int link(struct proc *, struct link_args *, int *);
 int unlink(struct proc *, struct unlink_args *, int *);
 int chdir(struct proc *, struct chdir_args *, int *);
 int fchdir(struct proc *, struct fchdir_args *, int *);
 int mknod(struct proc *, struct mknod_args *, int *);
 int chmod(struct proc *, struct chmod_args *, int *);
 int chown(struct proc *, struct chown_args *, int *);
 int getfsstat(struct proc *, struct getfsstat_args *, int *);
 int getpid(struct proc *, struct getpid_args *, int *);
 int setuid(struct proc *, struct setuid_args *, int *);
 int getuid(struct proc *, struct getuid_args *, int *);
 int geteuid(struct proc *, struct geteuid_args *, int *);
 int ptrace(struct proc *, struct ptrace_args *, int *);
 int recvmsg(struct proc *, struct recvmsg_args *, int *);
 int sendmsg(struct proc *, struct sendmsg_args *, int *);
 int recvfrom(struct proc *, struct recvfrom_args *, int *);
 int accept(struct proc *, struct accept_args *, int *);
 int getpeername(struct proc *, struct getpeername_args *, int *);
 int getsockname(struct proc *, struct getsockname_args *, int *);
 int access(struct proc *, struct access_args *, int *);
 int chflags(struct proc *, struct chflags_args *, int *);
 int fchflags(struct proc *, struct fchflags_args *, int *);
 int sync(struct proc *, struct sync_args *, int *);
 int kill(struct proc *, struct kill_args *, int *);
 int getppid(struct proc *, struct getppid_args *, int *);
 int dup(struct proc *, struct dup_args *, int *);
 int pipe(struct proc *, struct pipe_args *, int *);
 int getegid(struct proc *, struct getegid_args *, int *);
 int profil(struct proc *, struct profil_args *, int *);
 int sigaction(struct proc *, struct sigaction_args *, int *);
 int getgid(struct proc *, struct getgid_args *, int *);
 int sigprocmask(struct proc *, struct sigprocmask_args *, int *);
 int getlogin(struct proc *, struct getlogin_args *, int *);
 int setlogin(struct proc *, struct setlogin_args *, int *);
 int acct(struct proc *, struct acct_args *, int *);
 int sigpending(struct proc *, struct sigpending_args *, int *);
 int sigaltstack(struct proc *, struct sigaltstack_args *, int *);
 int ioctl(struct proc *, struct ioctl_args *, int *);
 int reboot(struct proc *, struct reboot_args *, int *);
 int revoke(struct proc *, struct revoke_args *, int *);
 int symlink(struct proc *, struct symlink_args *, int *);
 int readlink(struct proc *, struct readlink_args *, int *);
 int execve(struct proc *, struct execve_args *, int *);
 int umask(struct proc *, struct umask_args *, int *);
 int chroot(struct proc *, struct chroot_args *, int *);
 int msync(struct proc *, struct msync_args *, int *);
 int vfork(struct proc *, struct vfork_args *, int *);
 int munmap(struct proc *, struct munmap_args *, int *);
 int mprotect(struct proc *, struct mprotect_args *, int *);
 int madvise(struct proc *, struct madvise_args *, int *);
 int mincore(struct proc *, struct mincore_args *, int *);
 int getgroups(struct proc *, struct getgroups_args *, int *);
 int setgroups(struct proc *, struct setgroups_args *, int *);
 int getpgrp(struct proc *, struct getpgrp_args *, int *);
 int setpgid(struct proc *, struct setpgid_args *, int *);
 int setitimer(struct proc *, struct setitimer_args *, int *);
 int swapon(struct proc *, struct swapon_args *, int *);
 int getitimer(struct proc *, struct getitimer_args *, int *);
 int getdtablesize(struct proc *, struct getdtablesize_args *, int *);
 int dup2(struct proc *, struct dup2_args *, int *);
 int fcntl(struct proc *, struct fcntl_args *, int *);
 int select(struct proc *, struct select_args *, int *);
 int fsync(struct proc *, struct fsync_args *, int *);
 int setpriority(struct proc *, struct setpriority_args *, int *);
 int socket(struct proc *, struct socket_args *, int *);
 int connect(struct proc *, struct connect_args *, int *);
 int getpriority(struct proc *, struct getpriority_args *, int *);
 int bind(struct proc *, struct bind_args *, int *);
 int setsockopt(struct proc *, struct setsockopt_args *, int *);
 int listen(struct proc *, struct listen_args *, int *);
 int sigsuspend(struct proc *, struct sigsuspend_args *, int *);
 int gettimeofday(struct proc *, struct gettimeofday_args *, int *);
 int getrusage(struct proc *, struct getrusage_args *, int *);
 int getsockopt(struct proc *, struct getsockopt_args *, int *);
 int readv(struct proc *, struct readv_args *, user_ssize_t *);
 int writev(struct proc *, struct writev_args *, user_ssize_t *);
 int settimeofday(struct proc *, struct settimeofday_args *, int *);
 int fchown(struct proc *, struct fchown_args *, int *);
 int fchmod(struct proc *, struct fchmod_args *, int *);
 int setreuid(struct proc *, struct setreuid_args *, int *);
 int setregid(struct proc *, struct setregid_args *, int *);
 int rename(struct proc *, struct rename_args *, int *);
 int flock(struct proc *, struct flock_args *, int *);
 int mkfifo(struct proc *, struct mkfifo_args *, int *);
 int sendto(struct proc *, struct sendto_args *, int *);
 int shutdown(struct proc *, struct shutdown_args *, int *);
 int socketpair(struct proc *, struct socketpair_args *, int *);
 int mkdir(struct proc *, struct mkdir_args *, int *);
 int rmdir(struct proc *, struct rmdir_args *, int *);
 int utimes(struct proc *, struct utimes_args *, int *);
 int futimes(struct proc *, struct futimes_args *, int *);
 int adjtime(struct proc *, struct adjtime_args *, int *);
 int gethostuuid(struct proc *, struct gethostuuid_args *, int *);
 int setsid(struct proc *, struct setsid_args *, int *);
 int getpgid(struct proc *, struct getpgid_args *, int *);
 int setprivexec(struct proc *, struct setprivexec_args *, int *);
 int pread(struct proc *, struct pread_args *, user_ssize_t *);
 int pwrite(struct proc *, struct pwrite_args *, user_ssize_t *);
 int nfssvc(struct proc *, struct nfssvc_args *, int *);
 int statfs(struct proc *, struct statfs_args *, int *);
 int fstatfs(struct proc *, struct fstatfs_args *, int *);
 int unmount(struct proc *, struct unmount_args *, int *);
 int getfh(struct proc *, struct getfh_args *, int *);
 int quotactl(struct proc *, struct quotactl_args *, int *);
 int mount(struct proc *, struct mount_args *, int *);
 int csops(struct proc *, struct csops_args *, int *);
 int waitid(struct proc *, struct waitid_args *, int *);
 int add_profil(struct proc *, struct add_profil_args *, int *);
 int kdebug_trace(struct proc *, struct kdebug_trace_args *, int *);
 int setgid(struct proc *, struct setgid_args *, int *);
 int setegid(struct proc *, struct setegid_args *, int *);
 int seteuid(struct proc *, struct seteuid_args *, int *);
 int sigreturn(struct proc *, struct sigreturn_args *, int *);
 int chud(struct proc *, struct chud_args *, int *);
 int fdatasync(struct proc *, struct fdatasync_args *, int *);
 int stat(struct proc *, struct stat_args *, int *);
 int fstat(struct proc *, struct fstat_args *, int *);
 int lstat(struct proc *, struct lstat_args *, int *);
 int pathconf(struct proc *, struct pathconf_args *, int *);
 int fpathconf(struct proc *, struct fpathconf_args *, int *);
 int getrlimit(struct proc *, struct getrlimit_args *, int *);
 int setrlimit(struct proc *, struct setrlimit_args *, int *);
 int getdirentries(struct proc *, struct getdirentries_args *, int *);
 int mmap(struct proc *, struct mmap_args *, user_addr_t *);
 int lseek(struct proc *, struct lseek_args *, off_t *);
 int truncate(struct proc *, struct truncate_args *, int *);
 int ftruncate(struct proc *, struct ftruncate_args *, int *);
 int __sysctl(struct proc *, struct __sysctl_args *, int *);
 int mlock(struct proc *, struct mlock_args *, int *);
 int munlock(struct proc *, struct munlock_args *, int *);
 int undelete(struct proc *, struct undelete_args *, int *);
 int ATsocket(struct proc *, struct ATsocket_args *, int *);
 int ATgetmsg(struct proc *, struct ATgetmsg_args *, int *);
 int ATputmsg(struct proc *, struct ATputmsg_args *, int *);
 int ATPsndreq(struct proc *, struct ATPsndreq_args *, int *);
 int ATPsndrsp(struct proc *, struct ATPsndrsp_args *, int *);
 int ATPgetreq(struct proc *, struct ATPgetreq_args *, int *);
 int ATPgetrsp(struct proc *, struct ATPgetrsp_args *, int *);
 int getattrlist(struct proc *, struct getattrlist_args *, int *);
 int setattrlist(struct proc *, struct setattrlist_args *, int *);
 int getdirentriesattr(struct proc *, struct getdirentriesattr_args *, int *);
 int exchangedata(struct proc *, struct exchangedata_args *, int *);
 int searchfs(struct proc *, struct searchfs_args *, int *);
 int delete(struct proc *, struct delete_args *, int *);
 int copyfile(struct proc *, struct copyfile_args *, int *);
 int fgetattrlist(struct proc *, struct fgetattrlist_args *, int *);
 int fsetattrlist(struct proc *, struct fsetattrlist_args *, int *);
 int poll(struct proc *, struct poll_args *, int *);
 int watchevent(struct proc *, struct watchevent_args *, int *);
 int waitevent(struct proc *, struct waitevent_args *, int *);
 int modwatch(struct proc *, struct modwatch_args *, int *);
 int getxattr(struct proc *, struct getxattr_args *, user_ssize_t *);
 int fgetxattr(struct proc *, struct fgetxattr_args *, user_ssize_t *);
 int setxattr(struct proc *, struct setxattr_args *, int *);
 int fsetxattr(struct proc *, struct fsetxattr_args *, int *);
 int removexattr(struct proc *, struct removexattr_args *, int *);
 int fremovexattr(struct proc *, struct fremovexattr_args *, int *);
 int listxattr(struct proc *, struct listxattr_args *, user_ssize_t *);
 int flistxattr(struct proc *, struct flistxattr_args *, user_ssize_t *);
 int fsctl(struct proc *, struct fsctl_args *, int *);
 int initgroups(struct proc *, struct initgroups_args *, int *);
 int posix_spawn(struct proc *, struct posix_spawn_args *, int *);
 int ffsctl(struct proc *, struct ffsctl_args *, int *);
 int nfsclnt(struct proc *, struct nfsclnt_args *, int *);
 int fhopen(struct proc *, struct fhopen_args *, int *);
 int minherit(struct proc *, struct minherit_args *, int *);
 int semsys(struct proc *, struct semsys_args *, int *);
 int msgsys(struct proc *, struct msgsys_args *, int *);
 int shmsys(struct proc *, struct shmsys_args *, int *);
 int semctl(struct proc *, struct semctl_args *, int *);
 int semget(struct proc *, struct semget_args *, int *);
 int semop(struct proc *, struct semop_args *, int *);
 int msgctl(struct proc *, struct msgctl_args *, int *);
 int msgget(struct proc *, struct msgget_args *, int *);
 int msgsnd(struct proc *, struct msgsnd_args *, int *);
 int msgrcv(struct proc *, struct msgrcv_args *, user_ssize_t *);
 int shmat(struct proc *, struct shmat_args *, user_addr_t *);
 int shmctl(struct proc *, struct shmctl_args *, int *);
 int shmdt(struct proc *, struct shmdt_args *, int *);
 int shmget(struct proc *, struct shmget_args *, int *);
 int shm_open(struct proc *, struct shm_open_args *, int *);
 int shm_unlink(struct proc *, struct shm_unlink_args *, int *);
 int sem_open(struct proc *, struct sem_open_args *, user_addr_t *);
 int sem_close(struct proc *, struct sem_close_args *, int *);
 int sem_unlink(struct proc *, struct sem_unlink_args *, int *);
 int sem_wait(struct proc *, struct sem_wait_args *, int *);
 int sem_trywait(struct proc *, struct sem_trywait_args *, int *);
 int sem_post(struct proc *, struct sem_post_args *, int *);
 int sem_getvalue(struct proc *, struct sem_getvalue_args *, int *);
 int sem_init(struct proc *, struct sem_init_args *, int *);
 int sem_destroy(struct proc *, struct sem_destroy_args *, int *);
 int open_extended(struct proc *, struct open_extended_args *, int *);
 int umask_extended(struct proc *, struct umask_extended_args *, int *);
 int stat_extended(struct proc *, struct stat_extended_args *, int *);
 int lstat_extended(struct proc *, struct lstat_extended_args *, int *);
 int fstat_extended(struct proc *, struct fstat_extended_args *, int *);
 int chmod_extended(struct proc *, struct chmod_extended_args *, int *);
 int fchmod_extended(struct proc *, struct fchmod_extended_args *, int *);
 int access_extended(struct proc *, struct access_extended_args *, int *);
 int settid(struct proc *, struct settid_args *, int *);
 int gettid(struct proc *, struct gettid_args *, int *);
 int setsgroups(struct proc *, struct setsgroups_args *, int *);
 int getsgroups(struct proc *, struct getsgroups_args *, int *);
 int setwgroups(struct proc *, struct setwgroups_args *, int *);
 int getwgroups(struct proc *, struct getwgroups_args *, int *);
 int mkfifo_extended(struct proc *, struct mkfifo_extended_args *, int *);
 int mkdir_extended(struct proc *, struct mkdir_extended_args *, int *);
 int identitysvc(struct proc *, struct identitysvc_args *, int *);
 int shared_region_check_np(struct proc *, struct shared_region_check_np_args *, int *);
 int vm_pressure_monitor(struct proc *, struct vm_pressure_monitor_args *, int *);
 int psynch_rw_longrdlock(struct proc *, struct psynch_rw_longrdlock_args *, uint32_t *);
 int psynch_rw_yieldwrlock(struct proc *, struct psynch_rw_yieldwrlock_args *, uint32_t *);
 int psynch_rw_downgrade(struct proc *, struct psynch_rw_downgrade_args *, int *);
 int psynch_rw_upgrade(struct proc *, struct psynch_rw_upgrade_args *, uint32_t *);
 int psynch_mutexwait(struct proc *, struct psynch_mutexwait_args *, uint32_t *);
 int psynch_mutexdrop(struct proc *, struct psynch_mutexdrop_args *, uint32_t *);
 int psynch_cvbroad(struct proc *, struct psynch_cvbroad_args *, uint32_t *);
 int psynch_cvsignal(struct proc *, struct psynch_cvsignal_args *, uint32_t *);
 int psynch_cvwait(struct proc *, struct psynch_cvwait_args *, uint32_t *);
 int psynch_rw_rdlock(struct proc *, struct psynch_rw_rdlock_args *, uint32_t *);
 int psynch_rw_wrlock(struct proc *, struct psynch_rw_wrlock_args *, uint32_t *);
 int psynch_rw_unlock(struct proc *, struct psynch_rw_unlock_args *, uint32_t *);
 int psynch_rw_unlock2(struct proc *, struct psynch_rw_unlock2_args *, uint32_t *);
 int getsid(struct proc *, struct getsid_args *, int *);
 int settid_with_pid(struct proc *, struct settid_with_pid_args *, int *);
 int psynch_cvclrprepost(struct proc *, struct psynch_cvclrprepost_args *, int *);
 int aio_fsync(struct proc *, struct aio_fsync_args *, int *);
 int aio_return(struct proc *, struct aio_return_args *, user_ssize_t *);
 int aio_suspend(struct proc *, struct aio_suspend_args *, int *);
 int aio_cancel(struct proc *, struct aio_cancel_args *, int *);
 int aio_error(struct proc *, struct aio_error_args *, int *);
 int aio_read(struct proc *, struct aio_read_args *, int *);
 int aio_write(struct proc *, struct aio_write_args *, int *);
 int lio_listio(struct proc *, struct lio_listio_args *, int *);
 int iopolicysys(struct proc *, struct iopolicysys_args *, int *);
 int process_policy(struct proc *, struct process_policy_args *, int *);
 int mlockall(struct proc *, struct mlockall_args *, int *);
 int munlockall(struct proc *, struct munlockall_args *, int *);
 int issetugid(struct proc *, struct issetugid_args *, int *);
 int __pthread_kill(struct proc *, struct __pthread_kill_args *, int *);
 int __pthread_sigmask(struct proc *, struct __pthread_sigmask_args *, int *);
 int __sigwait(struct proc *, struct __sigwait_args *, int *);
 int __disable_threadsignal(struct proc *, struct __disable_threadsignal_args *, int *);
 int __pthread_markcancel(struct proc *, struct __pthread_markcancel_args *, int *);
 int __pthread_canceled(struct proc *, struct __pthread_canceled_args *, int *);
 int __semwait_signal(struct proc *, struct __semwait_signal_args *, int *);
 int proc_info(struct proc *, struct proc_info_args *, int *);
 int sendfile(struct proc *, struct sendfile_args *, int *);
 int stat64(struct proc *, struct stat64_args *, int *);
 int fstat64(struct proc *, struct fstat64_args *, int *);
 int lstat64(struct proc *, struct lstat64_args *, int *);
 int stat64_extended(struct proc *, struct stat64_extended_args *, int *);
 int lstat64_extended(struct proc *, struct lstat64_extended_args *, int *);
 int fstat64_extended(struct proc *, struct fstat64_extended_args *, int *);
 int getdirentries64(struct proc *, struct getdirentries64_args *, user_ssize_t *);
 int statfs64(struct proc *, struct statfs64_args *, int *);
 int fstatfs64(struct proc *, struct fstatfs64_args *, int *);
 int getfsstat64(struct proc *, struct getfsstat64_args *, int *);
 int __pthread_chdir(struct proc *, struct __pthread_chdir_args *, int *);
 int __pthread_fchdir(struct proc *, struct __pthread_fchdir_args *, int *);
 int audit(struct proc *, struct audit_args *, int *);
 int auditon(struct proc *, struct auditon_args *, int *);
 int getauid(struct proc *, struct getauid_args *, int *);
 int setauid(struct proc *, struct setauid_args *, int *);
 int getaudit(struct proc *, struct getaudit_args *, int *);
 int setaudit(struct proc *, struct setaudit_args *, int *);
 int getaudit_addr(struct proc *, struct getaudit_addr_args *, int *);
 int setaudit_addr(struct proc *, struct setaudit_addr_args *, int *);
 int auditctl(struct proc *, struct auditctl_args *, int *);
 int bsdthread_create(struct proc *, struct bsdthread_create_args *, user_addr_t *);
 int bsdthread_terminate(struct proc *, struct bsdthread_terminate_args *, int *);
 int kqueue(struct proc *, struct kqueue_args *, int *);
 int kevent(struct proc *, struct kevent_args *, int *);
 int lchown(struct proc *, struct lchown_args *, int *);
 int stack_snapshot(struct proc *, struct stack_snapshot_args *, int *);
 int bsdthread_register(struct proc *, struct bsdthread_register_args *, int *);
 int workq_open(struct proc *, struct workq_open_args *, int *);
 int workq_kernreturn(struct proc *, struct workq_kernreturn_args *, int *);
 int kevent64(struct proc *, struct kevent64_args *, int *);
 int __old_semwait_signal(struct proc *, struct __old_semwait_signal_args *, int *);
 int __old_semwait_signal_nocancel(struct proc *, struct __old_semwait_signal_nocancel_args *, int *);
 int thread_selfid(struct proc *, struct thread_selfid_args *, uint64_t *);
 int __mac_execve(struct proc *, struct __mac_execve_args *, int *);
 int __mac_syscall(struct proc *, struct __mac_syscall_args *, int *);
 int __mac_get_file(struct proc *, struct __mac_get_file_args *, int *);
 int __mac_set_file(struct proc *, struct __mac_set_file_args *, int *);
 int __mac_get_link(struct proc *, struct __mac_get_link_args *, int *);
 int __mac_set_link(struct proc *, struct __mac_set_link_args *, int *);
 int __mac_get_proc(struct proc *, struct __mac_get_proc_args *, int *);
 int __mac_set_proc(struct proc *, struct __mac_set_proc_args *, int *);
 int __mac_get_fd(struct proc *, struct __mac_get_fd_args *, int *);
 int __mac_set_fd(struct proc *, struct __mac_set_fd_args *, int *);
 int __mac_get_pid(struct proc *, struct __mac_get_pid_args *, int *);
 int __mac_get_lcid(struct proc *, struct __mac_get_lcid_args *, int *);
 int __mac_get_lctx(struct proc *, struct __mac_get_lctx_args *, int *);
 int __mac_set_lctx(struct proc *, struct __mac_set_lctx_args *, int *);
 int setlcid(struct proc *, struct setlcid_args *, int *);
 int getlcid(struct proc *, struct getlcid_args *, int *);
 int read_nocancel(struct proc *, struct read_nocancel_args *, user_ssize_t *);
 int write_nocancel(struct proc *, struct write_nocancel_args *, user_ssize_t *);
 int open_nocancel(struct proc *, struct open_nocancel_args *, int *);
 int close_nocancel(struct proc *, struct close_nocancel_args *, int *);
 int wait4_nocancel(struct proc *, struct wait4_nocancel_args *, int *);
 int recvmsg_nocancel(struct proc *, struct recvmsg_nocancel_args *, int *);
 int sendmsg_nocancel(struct proc *, struct sendmsg_nocancel_args *, int *);
 int recvfrom_nocancel(struct proc *, struct recvfrom_nocancel_args *, int *);
 int accept_nocancel(struct proc *, struct accept_nocancel_args *, int *);
 int msync_nocancel(struct proc *, struct msync_nocancel_args *, int *);
 int fcntl_nocancel(struct proc *, struct fcntl_nocancel_args *, int *);
 int select_nocancel(struct proc *, struct select_nocancel_args *, int *);
 int fsync_nocancel(struct proc *, struct fsync_nocancel_args *, int *);
 int connect_nocancel(struct proc *, struct connect_nocancel_args *, int *);
 int sigsuspend_nocancel(struct proc *, struct sigsuspend_nocancel_args *, int *);
 int readv_nocancel(struct proc *, struct readv_nocancel_args *, user_ssize_t *);
 int writev_nocancel(struct proc *, struct writev_nocancel_args *, user_ssize_t *);
 int sendto_nocancel(struct proc *, struct sendto_nocancel_args *, int *);
 int pread_nocancel(struct proc *, struct pread_nocancel_args *, user_ssize_t *);
 int pwrite_nocancel(struct proc *, struct pwrite_nocancel_args *, user_ssize_t *);
 int waitid_nocancel(struct proc *, struct waitid_nocancel_args *, int *);
 int poll_nocancel(struct proc *, struct poll_nocancel_args *, int *);
 int msgsnd_nocancel(struct proc *, struct msgsnd_nocancel_args *, int *);
 int msgrcv_nocancel(struct proc *, struct msgrcv_nocancel_args *, user_ssize_t *);
 int sem_wait_nocancel(struct proc *, struct sem_wait_nocancel_args *, int *);
 int aio_suspend_nocancel(struct proc *, struct aio_suspend_nocancel_args *, int *);
 int __sigwait_nocancel(struct proc *, struct __sigwait_nocancel_args *, int *);
 int __semwait_signal_nocancel(struct proc *, struct __semwait_signal_nocancel_args *, int *);
 int __mac_mount(struct proc *, struct __mac_mount_args *, int *);
 int __mac_get_mount(struct proc *, struct __mac_get_mount_args *, int *);
 int __mac_getfsstat(struct proc *, struct __mac_getfsstat_args *, int *);
 int fsgetpath(struct proc *, struct fsgetpath_args *, user_ssize_t *);
 int audit_session_self(struct proc *, struct audit_session_self_args *, mach_port_name_t *);
 int audit_session_join(struct proc *, struct audit_session_join_args *, int *);
 int fileport_makeport(struct proc *, struct fileport_makeport_args *, int *);
 int fileport_makefd(struct proc *, struct fileport_makefd_args *, int *);
 int audit_session_port(struct proc *, struct audit_session_port_args *, int *);
 int pid_suspend(struct proc *, struct pid_suspend_args *, int *);
 int pid_resume(struct proc *, struct pid_resume_args *, int *);
 int pid_hibernate(struct proc *, struct pid_hibernate_args *, int *);
 int pid_shutdown_sockets(struct proc *, struct pid_shutdown_sockets_args *, int *);
 int shared_region_map_and_slide_np(struct proc *, struct shared_region_map_and_slide_np_args *, int *);
 int kas_info(struct proc *, struct kas_info_args *, int *);
 */

#endif
