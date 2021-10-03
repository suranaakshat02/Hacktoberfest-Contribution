package json_error_log

import (
	"errors"
	"strconv"
	"testing"
)

func TestErrJson(t *testing.T) {
	for i := 0; i <= 10; i++ {
		err := errors.New("Ini Error " + strconv.Itoa(i))
		WriteError("err.json", err.Error())
	}
}

