package json_error_log

import "time"

type Error struct {
	Time  time.Time
	Error string
}

