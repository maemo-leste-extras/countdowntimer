#
# Regular cron jobs for the countdowntimer package
#
0 4	* * *	root	[ -x /usr/bin/countdowntimer_maintenance ] && /usr/bin/countdowntimer_maintenance
